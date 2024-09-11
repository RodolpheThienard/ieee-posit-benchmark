// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Mon Jul 22 11:30:23 2024
// Host        : emg2abtics-virtual-machine running 64-bit Ubuntu 22.04.4 LTS
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_2_test_axi_entree_sort_0_0_stub.v
// Design      : design_2_test_axi_entree_sort_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xck26-sfvc784-2LV-c
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "test_axi_entree_sortie,Vivado 2023.2" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(aclk, aresetn, s_axis_tvalid_x, 
  s_axis_tready_x, s_axis_tdata_x, s_axis_tlast_x, m_axis_tvalid_r, m_axis_tready_r, 
  m_axis_tdata_r, m_axis_tlast_r)
/* synthesis syn_black_box black_box_pad_pin="aresetn,s_axis_tvalid_x,s_axis_tready_x,s_axis_tdata_x[31:0],s_axis_tlast_x,m_axis_tvalid_r,m_axis_tready_r,m_axis_tdata_r[31:0],m_axis_tlast_r" */
/* synthesis syn_force_seq_prim="aclk" */;
  input aclk /* synthesis syn_isclock = 1 */;
  input aresetn;
  input s_axis_tvalid_x;
  output s_axis_tready_x;
  input [31:0]s_axis_tdata_x;
  input s_axis_tlast_x;
  output m_axis_tvalid_r;
  input m_axis_tready_r;
  output [31:0]m_axis_tdata_r;
  output m_axis_tlast_r;
endmodule
