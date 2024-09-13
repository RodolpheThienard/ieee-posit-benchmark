#include "xaxidma.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xstatus.h"
#include "xil_cache.h"

// DMA and FIFO device instances
XAxiDma AxiDma;

#define FIFO_BASE_ADDR  XPAR_AXIS_FIFO_0_BASEADDR
#define DMA_DEV_ID      XPAR_AXIDMA_0_DEVICE_ID
#define MEM_BASE_ADDR   0x01000000

#define RX_BUFFER_BASE  (MEM_BASE_ADDR + 0x00300000)
#define FIFO_TX_DATA_OFFSET  0x00  // Offset for FIFO data register (you need to adjust based on your FIFO IP)
#define FIFO_TX_CTRL_OFFSET  0x04  // Offset for FIFO control register (you need to adjust based on your FIFO IP)

// Function prototypes
int init_dma();
int fifo_send(u32 *data, u32 length);
int dma_transfer();
void write_fifo(u32 data);
u32 read_fifo();

int main()
{
    int status;
    u32 txData = 0x12345678;
    u32 rxData;

    // Initialize the DMA
    status = init_dma();
    if (status != XST_SUCCESS) {
        xil_printf("DMA initialization failed\n");
        return XST_FAILURE;
    }

    // Send data via FIFO
    status = fifo_send(&txData, 1);
    if (status != XST_SUCCESS) {
        xil_printf("FIFO send failed\n");
        return XST_FAILURE;
    }

    // Perform DMA transfer
    status = dma_transfer();
    if (status != XST_SUCCESS) {
        xil_printf("DMA transfer failed\n");
        return XST_FAILURE;
    }

    // Read received data
    rxData = *((u32 *) RX_BUFFER_BASE);
    xil_printf("Received data: 0x%08X\n", rxData);

    return 0;
}

int init_dma()
{
    XAxiDma_Config *cfg;

    cfg = XAxiDma_LookupConfig(DMA_DEV_ID);
    if (!cfg) {
        xil_printf("No config found for %d\n", DMA_DEV_ID);
        return XST_FAILURE;
    }

    int status = XAxiDma_CfgInitialize(&AxiDma, cfg);
    if (status != XST_SUCCESS) {
        xil_printf("DMA initialization failed\n");
        return status;
    }

    if (XAxiDma_HasSg(&AxiDma)) {
        xil_printf("Device configured as SG mode\n");
        return XST_FAILURE;
    }

    XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
    XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

    return XST_SUCCESS;
}

int fifo_send(u32 *data, u32 length)
{
    for (u32 i = 0; i < length; i++) {
        write_fifo(data[i]);
    }
    return XST_SUCCESS;
}

void write_fifo(u32 data)
{
    Xil_Out32(FIFO_BASE_ADDR + FIFO_TX_DATA_OFFSET, data);
}

int dma_transfer()
{
    int status;

    status = XAxiDma_SimpleTransfer(&AxiDma, (UINTPTR) RX_BUFFER_BASE, sizeof(u32), XAXIDMA_DEVICE_TO_DMA);
    if (status != XST_SUCCESS) {
        xil_printf("DMA receive setup failed\n");
        return XST_FAILURE;
    }

    while (XAxiDma_Busy(&AxiDma, XAXIDMA_DEVICE_TO_DMA)) {
        // Wait for DMA transfer to complete
    }

    Xil_DCacheInvalidateRange((UINTPTR) RX_BUFFER_BASE, sizeof(u32));

    return XST_SUCCESS;
}
