// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
// Date        : Mon Jul 22 11:30:24 2024
// Host        : emg2abtics-virtual-machine running 64-bit Ubuntu 22.04.4 LTS
// Command     : write_verilog -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_2_test_axi_entree_sort_0_0_sim_netlist.v
// Design      : design_2_test_axi_entree_sort_0_0
// Purpose     : This verilog netlist is a functional simulation representation of the design and should not be modified
//               or synthesized. This netlist cannot be used for SDF annotated simulation.
// Device      : xck26-sfvc784-2LV-c
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CHECK_LICENSE_TYPE = "design_2_test_axi_entree_sort_0_0,test_axi_entree_sortie,{}" *) (* DowngradeIPIdentifiedWarnings = "yes" *) (* IP_DEFINITION_SOURCE = "module_ref" *) 
(* X_CORE_INFO = "test_axi_entree_sortie,Vivado 2023.2" *) 
(* NotValidForBitStream *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix
   (aclk,
    aresetn,
    s_axis_tvalid_x,
    s_axis_tready_x,
    s_axis_tdata_x,
    s_axis_tlast_x,
    m_axis_tvalid_r,
    m_axis_tready_r,
    m_axis_tdata_r,
    m_axis_tlast_r);
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 aclk CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME aclk, ASSOCIATED_BUSIF m_axis_r:s_axis_x, ASSOCIATED_RESET aresetn, FREQ_HZ 96968727, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, INSERT_VIP 0" *) input aclk;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 aresetn RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME aresetn, POLARITY ACTIVE_LOW, INSERT_VIP 0" *) input aresetn;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 s_axis_x TVALID" *) input s_axis_tvalid_x;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 s_axis_x TREADY" *) output s_axis_tready_x;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 s_axis_x TDATA" *) input [31:0]s_axis_tdata_x;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 s_axis_x TLAST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME s_axis_x, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 96968727, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, LAYERED_METADATA undef, INSERT_VIP 0" *) input s_axis_tlast_x;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 m_axis_r TVALID" *) output m_axis_tvalid_r;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 m_axis_r TREADY" *) input m_axis_tready_r;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 m_axis_r TDATA" *) output [31:0]m_axis_tdata_r;
  (* X_INTERFACE_INFO = "xilinx.com:interface:axis:1.0 m_axis_r TLAST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME m_axis_r, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 96968727, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, LAYERED_METADATA undef, INSERT_VIP 0" *) output m_axis_tlast_r;

  wire aclk;
  wire aresetn;
  wire [31:0]m_axis_tdata_r;
  wire m_axis_tlast_r;
  wire m_axis_tready_r;
  wire m_axis_tvalid_r;
  wire [31:0]s_axis_tdata_x;
  wire s_axis_tlast_x;
  wire s_axis_tvalid_x;

  assign s_axis_tready_x = m_axis_tvalid_r;
  decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie inst
       (.aclk(aclk),
        .aresetn(aresetn),
        .m_axis_tdata_r(m_axis_tdata_r),
        .m_axis_tlast_r(m_axis_tlast_r),
        .m_axis_tready_r(m_axis_tready_r),
        .m_axis_tvalid_r(m_axis_tvalid_r),
        .s_axis_tdata_x(s_axis_tdata_x),
        .s_axis_tlast_x(s_axis_tlast_x),
        .s_axis_tvalid_x(s_axis_tvalid_x));
endmodule

module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie
   (m_axis_tvalid_r,
    m_axis_tdata_r,
    m_axis_tlast_r,
    aclk,
    s_axis_tdata_x,
    aresetn,
    s_axis_tvalid_x,
    m_axis_tready_r,
    s_axis_tlast_x);
  output m_axis_tvalid_r;
  output [31:0]m_axis_tdata_r;
  output m_axis_tlast_r;
  input aclk;
  input [31:0]s_axis_tdata_x;
  input aresetn;
  input s_axis_tvalid_x;
  input m_axis_tready_r;
  input s_axis_tlast_x;

  wire aclk;
  wire aresetn;
  wire [31:0]m_axis_tdata_r;
  wire m_axis_tlast_r;
  wire m_axis_tready_r;
  wire m_axis_tvalid_r;
  wire [31:0]s_axis_tdata_x;
  wire s_axis_tlast_x;
  wire s_axis_tvalid_x;
  wire s_tlast_int;
  wire s_tvalid_int0;
  wire s_tvalid_int_i_2_n_0;

  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[0] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[0]),
        .Q(m_axis_tdata_r[0]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[10] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[10]),
        .Q(m_axis_tdata_r[10]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[11] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[11]),
        .Q(m_axis_tdata_r[11]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[12] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[12]),
        .Q(m_axis_tdata_r[12]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[13] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[13]),
        .Q(m_axis_tdata_r[13]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[14] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[14]),
        .Q(m_axis_tdata_r[14]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[15] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[15]),
        .Q(m_axis_tdata_r[15]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[16] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[16]),
        .Q(m_axis_tdata_r[16]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[17] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[17]),
        .Q(m_axis_tdata_r[17]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[18] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[18]),
        .Q(m_axis_tdata_r[18]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[19] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[19]),
        .Q(m_axis_tdata_r[19]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[1] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[1]),
        .Q(m_axis_tdata_r[1]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[20] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[20]),
        .Q(m_axis_tdata_r[20]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[21] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[21]),
        .Q(m_axis_tdata_r[21]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[22] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[22]),
        .Q(m_axis_tdata_r[22]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[23] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[23]),
        .Q(m_axis_tdata_r[23]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[24] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[24]),
        .Q(m_axis_tdata_r[24]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[25] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[25]),
        .Q(m_axis_tdata_r[25]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[26] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[26]),
        .Q(m_axis_tdata_r[26]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[27] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[27]),
        .Q(m_axis_tdata_r[27]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[28] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[28]),
        .Q(m_axis_tdata_r[28]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[29] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[29]),
        .Q(m_axis_tdata_r[29]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[2] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[2]),
        .Q(m_axis_tdata_r[2]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[30] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[30]),
        .Q(m_axis_tdata_r[30]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[31] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[31]),
        .Q(m_axis_tdata_r[31]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[3] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[3]),
        .Q(m_axis_tdata_r[3]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[4] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[4]),
        .Q(m_axis_tdata_r[4]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[5] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[5]),
        .Q(m_axis_tdata_r[5]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[6] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[6]),
        .Q(m_axis_tdata_r[6]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[7] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[7]),
        .Q(m_axis_tdata_r[7]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[8] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[8]),
        .Q(m_axis_tdata_r[8]));
  FDCE #(
    .INIT(1'b0)) 
    \s_tdata_int_reg[9] 
       (.C(aclk),
        .CE(s_tvalid_int0),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_axis_tdata_x[9]),
        .Q(m_axis_tdata_r[9]));
  LUT3 #(
    .INIT(8'h80)) 
    s_tlast_int_i_1
       (.I0(s_axis_tvalid_x),
        .I1(m_axis_tready_r),
        .I2(s_axis_tlast_x),
        .O(s_tlast_int));
  FDCE #(
    .INIT(1'b0)) 
    s_tlast_int_reg
       (.C(aclk),
        .CE(1'b1),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_tlast_int),
        .Q(m_axis_tlast_r));
  LUT2 #(
    .INIT(4'h8)) 
    s_tvalid_int_i_1
       (.I0(m_axis_tready_r),
        .I1(s_axis_tvalid_x),
        .O(s_tvalid_int0));
  LUT1 #(
    .INIT(2'h1)) 
    s_tvalid_int_i_2
       (.I0(aresetn),
        .O(s_tvalid_int_i_2_n_0));
  FDCE #(
    .INIT(1'b0)) 
    s_tvalid_int_reg
       (.C(aclk),
        .CE(1'b1),
        .CLR(s_tvalid_int_i_2_n_0),
        .D(s_tvalid_int0),
        .Q(m_axis_tvalid_r));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
