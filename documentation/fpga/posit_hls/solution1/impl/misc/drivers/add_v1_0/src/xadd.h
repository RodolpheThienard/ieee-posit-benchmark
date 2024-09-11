// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XADD_H
#define XADD_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xadd_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XAdd_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XAdd;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAdd_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAdd_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAdd_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAdd_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XAdd_Initialize(XAdd *InstancePtr, UINTPTR BaseAddress);
XAdd_Config* XAdd_LookupConfig(UINTPTR BaseAddress);
#else
int XAdd_Initialize(XAdd *InstancePtr, u16 DeviceId);
XAdd_Config* XAdd_LookupConfig(u16 DeviceId);
#endif
int XAdd_CfgInitialize(XAdd *InstancePtr, XAdd_Config *ConfigPtr);
#else
int XAdd_Initialize(XAdd *InstancePtr, const char* InstanceName);
int XAdd_Release(XAdd *InstancePtr);
#endif


void XAdd_Set_in_a(XAdd *InstancePtr, u32 Data);
u32 XAdd_Get_in_a(XAdd *InstancePtr);
void XAdd_Set_in_b(XAdd *InstancePtr, u32 Data);
u32 XAdd_Get_in_b(XAdd *InstancePtr);
void XAdd_Set_out_c(XAdd *InstancePtr, u32 Data);
u32 XAdd_Get_out_c(XAdd *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
