// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// control
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of in_a
//        bit 31~0 - in_a[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of in_b
//        bit 31~0 - in_b[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of out_c
//        bit 31~0 - out_c[31:0] (Read/Write)
// 0x24 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XADD_CONTROL_ADDR_IN_A_DATA  0x10
#define XADD_CONTROL_BITS_IN_A_DATA  32
#define XADD_CONTROL_ADDR_IN_B_DATA  0x18
#define XADD_CONTROL_BITS_IN_B_DATA  32
#define XADD_CONTROL_ADDR_OUT_C_DATA 0x20
#define XADD_CONTROL_BITS_OUT_C_DATA 32

