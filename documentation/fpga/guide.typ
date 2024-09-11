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
#image("images/ddr_vivado_kria.png")
Mise en place d'une documentation explicitant les changements nécessaires à faire pour faire fonctionner la carte AMD Xilinx Kria KV260 disponible dans le fichier suivant : #underline("zynq_modification.pdf")

== TODO
#image("images/design_vivado.png")

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
