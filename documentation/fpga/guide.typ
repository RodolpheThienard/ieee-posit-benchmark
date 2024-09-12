#set page(numbering: "1")
#set heading(numbering: "1.1.1.a")
#show raw.where(block: true): box.with(
    fill: luma(240),
    inset: (x: 5pt, y: 2pt),
    outset: (y: 3pt),
    radius: 2pt
  )

#show raw.where(block: false): box.with(
    fill: luma(240),
    inset: (x: 5pt, y: 2pt),
    outset: (y: 3pt),
    radius: 2pt
  )

= Guide FPGA
Aides des dossiers suivants : 
- AXI GPIO documentation ABTICS
- AXI STREAM documentation ABTICS
- AXI UARTLITE documentation ABTICS


= Vivado
== Fonctionnement de la carte Kria
Mise en place d'une documentation explicitant les changements nécessaires à faire pour faire fonctionner la carte AMD Xilinx Kria KV260 disponible dans le fichier suivant : #underline("zynq_modification.pdf"). Ces modifications sont à faire sur l'IP Zync Ultrascale +.
#image("images/ddr_vivado_kria.png")

= Design DMA
== Vivado
Dans cette partie, nous avons mis en place un design permettant de faire l'envoie et la réception d'une donnée de taille 32 bits grace aux DMA.
#image("images/design_vivado.png")

== Vitis classic
Fonctionne pas mais code accessible dans `project_2`

```c
#include "xparameters.h"
#include "xaxidma.h"
#include "xil_printf.h"
#include "xil_cache.h"

#define DMA_DEV_ID		XPAR_AXIDMA_0_DEVICE_ID
#define DDR_BASE_ADDR	XPAR_PSU_DDR_0_S_AXI_BASEADDR
#define MEM_BASE_ADDR	(DDR_BASE_ADDR + 0xA000000)

#define TX_BUFFER_BASE	(MEM_BASE_ADDR + 0x00100000)
#define RX_BUFFER_BASE	(MEM_BASE_ADDR + 0x00300000)
#define RX_BUFFER_HIGH	(MEM_BASE_ADDR + 0x004FFFFF)

#define MAX_PKT_LEN		0x20
#define NUMBER_OF_TRANSFERS	10

XAxiDma AxiDma;

int CheckData() {
    u32 *TxBufferPtr = (u32 *)TX_BUFFER_BASE;
    u32 *RxBufferPtr = (u32 *)RX_BUFFER_BASE;
    u32 Index;

    for (Index = 0; Index < MAX_PKT_LEN; Index++) {
        TxBufferPtr[Index] = Index + 0xC;
        RxBufferPtr[Index] = 0;
    }

    Xil_DCacheFlushRange((UINTPTR)TxBufferPtr, MAX_PKT_LEN * sizeof(u32));
    // Send a packet
    int Status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR)RxBufferPtr, MAX_PKT_LEN * sizeof(u32), XAXIDMA_DEVICE_TO_DMA);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }
    Status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR)TxBufferPtr, MAX_PKT_LEN * sizeof(u32), XAXIDMA_DMA_TO_DEVICE);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }
    while ((XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE)) || (XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA))) {
        // Wait
    }
    // Invalidate the cache to receive the data
    Xil_DCacheInvalidateRange((UINTPTR)RxBufferPtr, MAX_PKT_LEN * sizeof(u32));
    for (Index = 0; Index < MAX_PKT_LEN; Index++) {
        if (RxBufferPtr[Index] != TxBufferPtr[Index]) {
            xil_printf("Data error %d: %x/%x\r\n", Index, (unsigned int)RxBufferPtr[Index], (unsigned int)TxBufferPtr[Index]);
            return XST_FAILURE;
        }
    }
    return XST_SUCCESS;
}
```

```c
int main() {
    int Status;
    XAxiDma_Config *Config;
    xil_printf("init\n");

    // Initialize the XAxiDma device.
    Config = XAxiDma_LookupConfig(DMA_DEV_ID);
    if (!Config) {
        xil_printf("No config found for %d\r\n", DMA_DEV_ID);
        return XST_FAILURE;
    }

    Status = XAxiDma_CfgInitialize(&AxiDma, Config);
    if (Status != XST_SUCCESS) {
        xil_printf("Initialization failed %d\r\n", Status);
        return XST_FAILURE;
    }

    if (XAxiDma_HasSg(&AxiDma)) {
        xil_printf("Device configured as SG mode\r\n");
        return XST_FAILURE;
    }

    // Disable interrupts, we use polling mode.
    XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
    XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

    // Transmit and receive the data.
    Status = CheckData();

    if (Status != XST_SUCCESS) {
        xil_printf("Failed data check\r\n");
        return XST_FAILURE;
    }

    xil_printf("Successfully ran AXI DMA example\r\n");
    return XST_SUCCESS;
}

```
#image("images/build.png", height: 30%)

== Connexion FPGA
Il faut connecter le FPGA et lancer les commandes suivante dans le `XSCT Console` : 

```
Test du design :
 - Test envoie une donnée d'une adresse à une autre : 
    - initialisation du fpga :
        connect
        targets -set -filter {name =~ "PSU"}
        mwr 0xffca0010 0x0
        mwr 0xff5e0200 0x0100
        rst -system
    - Run programme : 
```
#image("images/connect_fpga.png", height: 30%)

#image("images/run.png", height: 30%)


= Vitis HLS


Mise en place d'un code d'addition de 2 float format 32 bits simple avec un interfaçage axi pour Vivado.

```c
#include "stdio.h"
#include "add.h"

void add(data_h in_a, data_h in_b, data_h out_c)
{
#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=in_a
#pragma HLS INTERFACE s_axilite port=in_b
#pragma HLS INTERFACE s_axilite port=out_c

    out_c = in_a + in_b;
}```

```c
#ifndef _MY_ADD_H_
#define _MY_ADD_H_

typedef float data_h;

void add(data_h in_a, data_h in_b, data_h out_c);

#endif
```

Dans Vitis HLS, il est indispensable, pour que la génération du code VHDL, de faire un test.

```c
#include "stdio.h"
#include "add.h"

int main() {
	data_h a,b,c;

	a = 1.0;
	b = 2.0;

	add(a, b, c);
	if (c == 3.0){
		printf("test passed !\n");
		return 0;
  }
	return 1;
}
```

Afin de pouvoir obtenir une IP compilée il faut valider plusieurs étapes dans Vitis HLS :
- La synthèse :
Les paramètres mis :

#image("images/synthese1.png", height: 30%)
Le résultat obtenu :

#image("images/synthese2.png")

- La simulation :
Les paramètres mis :

#image("images/simulation1.png", height: 30%)
Le résultat obtenu :

#image("images/simulation2.png")

- L'implémentation :
Les paramètres mis :

#image("images/implementation1.png", height: 30%)
Le résultat obtenu :

#image("images/implementation2.png")
