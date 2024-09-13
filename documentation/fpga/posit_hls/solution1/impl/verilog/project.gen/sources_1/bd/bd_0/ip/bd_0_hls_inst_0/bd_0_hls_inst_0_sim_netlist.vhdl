-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
-- Date        : Wed Aug 21 03:06:51 2024
-- Host        : emg2abtics-virtual-machine running 64-bit Ubuntu 22.04.4 LTS
-- Command     : write_vhdl -force -mode funcsim
--               /home/emg2-abtics/posit_hls/solution1/impl/verilog/project.gen/sources_1/bd/bd_0/ip/bd_0_hls_inst_0/bd_0_hls_inst_0_sim_netlist.vhdl
-- Design      : bd_0_hls_inst_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xck26-sfvc784-2LV-c
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity bd_0_hls_inst_0_add_control_s_axi is
  port (
    s_axi_control_BVALID : out STD_LOGIC;
    \FSM_onehot_wstate_reg[2]_0\ : out STD_LOGIC;
    \FSM_onehot_wstate_reg[1]_0\ : out STD_LOGIC;
    s_axi_control_RVALID : out STD_LOGIC;
    \FSM_onehot_rstate_reg[1]_0\ : out STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    ap_rst_n : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 5 downto 0 )
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of bd_0_hls_inst_0_add_control_s_axi : entity is "add_control_s_axi";
end bd_0_hls_inst_0_add_control_s_axi;

architecture STRUCTURE of bd_0_hls_inst_0_add_control_s_axi is
  signal \FSM_onehot_rstate[1]_i_1_n_0\ : STD_LOGIC;
  signal \FSM_onehot_rstate[2]_i_1_n_0\ : STD_LOGIC;
  signal \^fsm_onehot_rstate_reg[1]_0\ : STD_LOGIC;
  signal \FSM_onehot_wstate[1]_i_2_n_0\ : STD_LOGIC;
  signal \FSM_onehot_wstate[2]_i_1_n_0\ : STD_LOGIC;
  signal \FSM_onehot_wstate[3]_i_1_n_0\ : STD_LOGIC;
  signal \^fsm_onehot_wstate_reg[1]_0\ : STD_LOGIC;
  signal \^fsm_onehot_wstate_reg[2]_0\ : STD_LOGIC;
  signal ap_rst_n_inv : STD_LOGIC;
  signal int_in_a : STD_LOGIC;
  signal int_in_a0 : STD_LOGIC_VECTOR ( 31 downto 0 );
  signal \int_in_a[31]_i_3_n_0\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[0]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[10]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[11]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[12]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[13]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[14]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[15]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[16]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[17]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[18]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[19]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[1]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[20]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[21]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[22]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[23]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[24]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[25]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[26]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[27]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[28]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[29]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[2]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[30]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[31]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[3]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[4]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[5]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[6]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[7]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[8]\ : STD_LOGIC;
  signal \int_in_a_reg_n_0_[9]\ : STD_LOGIC;
  signal int_in_b : STD_LOGIC;
  signal int_in_b0 : STD_LOGIC_VECTOR ( 31 downto 0 );
  signal \int_in_b_reg_n_0_[0]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[10]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[11]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[12]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[13]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[14]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[15]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[16]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[17]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[18]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[19]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[1]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[20]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[21]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[22]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[23]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[24]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[25]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[26]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[27]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[28]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[29]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[2]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[30]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[31]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[3]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[4]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[5]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[6]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[7]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[8]\ : STD_LOGIC;
  signal \int_in_b_reg_n_0_[9]\ : STD_LOGIC;
  signal int_out_c : STD_LOGIC;
  signal int_out_c0 : STD_LOGIC_VECTOR ( 31 downto 0 );
  signal \int_out_c[31]_i_3_n_0\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[0]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[10]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[11]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[12]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[13]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[14]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[15]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[16]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[17]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[18]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[19]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[1]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[20]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[21]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[22]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[23]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[24]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[25]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[26]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[27]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[28]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[29]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[2]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[30]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[31]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[3]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[4]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[5]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[6]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[7]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[8]\ : STD_LOGIC;
  signal \int_out_c_reg_n_0_[9]\ : STD_LOGIC;
  signal rdata : STD_LOGIC_VECTOR ( 31 downto 0 );
  signal \rdata[31]_i_1_n_0\ : STD_LOGIC;
  signal \rdata[31]_i_3_n_0\ : STD_LOGIC;
  signal \rdata[31]_i_4_n_0\ : STD_LOGIC;
  signal \rdata[31]_i_5_n_0\ : STD_LOGIC;
  signal \^s_axi_control_bvalid\ : STD_LOGIC;
  signal \^s_axi_control_rvalid\ : STD_LOGIC;
  signal waddr : STD_LOGIC;
  signal \waddr_reg_n_0_[0]\ : STD_LOGIC;
  signal \waddr_reg_n_0_[1]\ : STD_LOGIC;
  signal \waddr_reg_n_0_[2]\ : STD_LOGIC;
  signal \waddr_reg_n_0_[3]\ : STD_LOGIC;
  signal \waddr_reg_n_0_[4]\ : STD_LOGIC;
  signal \waddr_reg_n_0_[5]\ : STD_LOGIC;
  attribute SOFT_HLUTNM : string;
  attribute SOFT_HLUTNM of \FSM_onehot_rstate[1]_i_1\ : label is "soft_lutpair1";
  attribute SOFT_HLUTNM of \FSM_onehot_rstate[2]_i_1\ : label is "soft_lutpair1";
  attribute FSM_ENCODED_STATES : string;
  attribute FSM_ENCODED_STATES of \FSM_onehot_rstate_reg[1]\ : label is "RDIDLE:010,RDDATA:100,iSTATE:001";
  attribute FSM_ENCODED_STATES of \FSM_onehot_rstate_reg[2]\ : label is "RDIDLE:010,RDDATA:100,iSTATE:001";
  attribute FSM_ENCODED_STATES of \FSM_onehot_wstate_reg[1]\ : label is "WRDATA:0100,WRRESP:1000,WRIDLE:0010,iSTATE:0001";
  attribute FSM_ENCODED_STATES of \FSM_onehot_wstate_reg[2]\ : label is "WRDATA:0100,WRRESP:1000,WRIDLE:0010,iSTATE:0001";
  attribute FSM_ENCODED_STATES of \FSM_onehot_wstate_reg[3]\ : label is "WRDATA:0100,WRRESP:1000,WRIDLE:0010,iSTATE:0001";
  attribute SOFT_HLUTNM of \int_in_a[0]_i_1\ : label is "soft_lutpair33";
  attribute SOFT_HLUTNM of \int_in_a[10]_i_1\ : label is "soft_lutpair23";
  attribute SOFT_HLUTNM of \int_in_a[11]_i_1\ : label is "soft_lutpair22";
  attribute SOFT_HLUTNM of \int_in_a[12]_i_1\ : label is "soft_lutpair21";
  attribute SOFT_HLUTNM of \int_in_a[13]_i_1\ : label is "soft_lutpair20";
  attribute SOFT_HLUTNM of \int_in_a[14]_i_1\ : label is "soft_lutpair19";
  attribute SOFT_HLUTNM of \int_in_a[15]_i_1\ : label is "soft_lutpair18";
  attribute SOFT_HLUTNM of \int_in_a[16]_i_1\ : label is "soft_lutpair17";
  attribute SOFT_HLUTNM of \int_in_a[17]_i_1\ : label is "soft_lutpair16";
  attribute SOFT_HLUTNM of \int_in_a[18]_i_1\ : label is "soft_lutpair15";
  attribute SOFT_HLUTNM of \int_in_a[19]_i_1\ : label is "soft_lutpair14";
  attribute SOFT_HLUTNM of \int_in_a[1]_i_1\ : label is "soft_lutpair32";
  attribute SOFT_HLUTNM of \int_in_a[20]_i_1\ : label is "soft_lutpair13";
  attribute SOFT_HLUTNM of \int_in_a[21]_i_1\ : label is "soft_lutpair12";
  attribute SOFT_HLUTNM of \int_in_a[22]_i_1\ : label is "soft_lutpair11";
  attribute SOFT_HLUTNM of \int_in_a[23]_i_1\ : label is "soft_lutpair10";
  attribute SOFT_HLUTNM of \int_in_a[24]_i_1\ : label is "soft_lutpair9";
  attribute SOFT_HLUTNM of \int_in_a[25]_i_1\ : label is "soft_lutpair8";
  attribute SOFT_HLUTNM of \int_in_a[26]_i_1\ : label is "soft_lutpair7";
  attribute SOFT_HLUTNM of \int_in_a[27]_i_1\ : label is "soft_lutpair6";
  attribute SOFT_HLUTNM of \int_in_a[28]_i_1\ : label is "soft_lutpair5";
  attribute SOFT_HLUTNM of \int_in_a[29]_i_1\ : label is "soft_lutpair4";
  attribute SOFT_HLUTNM of \int_in_a[2]_i_1\ : label is "soft_lutpair31";
  attribute SOFT_HLUTNM of \int_in_a[30]_i_1\ : label is "soft_lutpair3";
  attribute SOFT_HLUTNM of \int_in_a[31]_i_2\ : label is "soft_lutpair2";
  attribute SOFT_HLUTNM of \int_in_a[31]_i_3\ : label is "soft_lutpair0";
  attribute SOFT_HLUTNM of \int_in_a[3]_i_1\ : label is "soft_lutpair30";
  attribute SOFT_HLUTNM of \int_in_a[4]_i_1\ : label is "soft_lutpair29";
  attribute SOFT_HLUTNM of \int_in_a[5]_i_1\ : label is "soft_lutpair28";
  attribute SOFT_HLUTNM of \int_in_a[6]_i_1\ : label is "soft_lutpair27";
  attribute SOFT_HLUTNM of \int_in_a[7]_i_1\ : label is "soft_lutpair26";
  attribute SOFT_HLUTNM of \int_in_a[8]_i_1\ : label is "soft_lutpair25";
  attribute SOFT_HLUTNM of \int_in_a[9]_i_1\ : label is "soft_lutpair24";
  attribute SOFT_HLUTNM of \int_in_b[0]_i_1\ : label is "soft_lutpair33";
  attribute SOFT_HLUTNM of \int_in_b[10]_i_1\ : label is "soft_lutpair23";
  attribute SOFT_HLUTNM of \int_in_b[11]_i_1\ : label is "soft_lutpair22";
  attribute SOFT_HLUTNM of \int_in_b[12]_i_1\ : label is "soft_lutpair21";
  attribute SOFT_HLUTNM of \int_in_b[13]_i_1\ : label is "soft_lutpair20";
  attribute SOFT_HLUTNM of \int_in_b[14]_i_1\ : label is "soft_lutpair19";
  attribute SOFT_HLUTNM of \int_in_b[15]_i_1\ : label is "soft_lutpair18";
  attribute SOFT_HLUTNM of \int_in_b[16]_i_1\ : label is "soft_lutpair17";
  attribute SOFT_HLUTNM of \int_in_b[17]_i_1\ : label is "soft_lutpair16";
  attribute SOFT_HLUTNM of \int_in_b[18]_i_1\ : label is "soft_lutpair15";
  attribute SOFT_HLUTNM of \int_in_b[19]_i_1\ : label is "soft_lutpair14";
  attribute SOFT_HLUTNM of \int_in_b[1]_i_1\ : label is "soft_lutpair32";
  attribute SOFT_HLUTNM of \int_in_b[20]_i_1\ : label is "soft_lutpair13";
  attribute SOFT_HLUTNM of \int_in_b[21]_i_1\ : label is "soft_lutpair12";
  attribute SOFT_HLUTNM of \int_in_b[22]_i_1\ : label is "soft_lutpair11";
  attribute SOFT_HLUTNM of \int_in_b[23]_i_1\ : label is "soft_lutpair10";
  attribute SOFT_HLUTNM of \int_in_b[24]_i_1\ : label is "soft_lutpair9";
  attribute SOFT_HLUTNM of \int_in_b[25]_i_1\ : label is "soft_lutpair8";
  attribute SOFT_HLUTNM of \int_in_b[26]_i_1\ : label is "soft_lutpair7";
  attribute SOFT_HLUTNM of \int_in_b[27]_i_1\ : label is "soft_lutpair6";
  attribute SOFT_HLUTNM of \int_in_b[28]_i_1\ : label is "soft_lutpair5";
  attribute SOFT_HLUTNM of \int_in_b[29]_i_1\ : label is "soft_lutpair4";
  attribute SOFT_HLUTNM of \int_in_b[2]_i_1\ : label is "soft_lutpair31";
  attribute SOFT_HLUTNM of \int_in_b[30]_i_1\ : label is "soft_lutpair3";
  attribute SOFT_HLUTNM of \int_in_b[31]_i_2\ : label is "soft_lutpair2";
  attribute SOFT_HLUTNM of \int_in_b[3]_i_1\ : label is "soft_lutpair30";
  attribute SOFT_HLUTNM of \int_in_b[4]_i_1\ : label is "soft_lutpair29";
  attribute SOFT_HLUTNM of \int_in_b[5]_i_1\ : label is "soft_lutpair28";
  attribute SOFT_HLUTNM of \int_in_b[6]_i_1\ : label is "soft_lutpair27";
  attribute SOFT_HLUTNM of \int_in_b[7]_i_1\ : label is "soft_lutpair26";
  attribute SOFT_HLUTNM of \int_in_b[8]_i_1\ : label is "soft_lutpair25";
  attribute SOFT_HLUTNM of \int_in_b[9]_i_1\ : label is "soft_lutpair24";
  attribute SOFT_HLUTNM of \int_out_c[0]_i_1\ : label is "soft_lutpair49";
  attribute SOFT_HLUTNM of \int_out_c[10]_i_1\ : label is "soft_lutpair44";
  attribute SOFT_HLUTNM of \int_out_c[11]_i_1\ : label is "soft_lutpair44";
  attribute SOFT_HLUTNM of \int_out_c[12]_i_1\ : label is "soft_lutpair43";
  attribute SOFT_HLUTNM of \int_out_c[13]_i_1\ : label is "soft_lutpair43";
  attribute SOFT_HLUTNM of \int_out_c[14]_i_1\ : label is "soft_lutpair42";
  attribute SOFT_HLUTNM of \int_out_c[15]_i_1\ : label is "soft_lutpair42";
  attribute SOFT_HLUTNM of \int_out_c[16]_i_1\ : label is "soft_lutpair41";
  attribute SOFT_HLUTNM of \int_out_c[17]_i_1\ : label is "soft_lutpair41";
  attribute SOFT_HLUTNM of \int_out_c[18]_i_1\ : label is "soft_lutpair40";
  attribute SOFT_HLUTNM of \int_out_c[19]_i_1\ : label is "soft_lutpair40";
  attribute SOFT_HLUTNM of \int_out_c[1]_i_1\ : label is "soft_lutpair49";
  attribute SOFT_HLUTNM of \int_out_c[20]_i_1\ : label is "soft_lutpair39";
  attribute SOFT_HLUTNM of \int_out_c[21]_i_1\ : label is "soft_lutpair39";
  attribute SOFT_HLUTNM of \int_out_c[22]_i_1\ : label is "soft_lutpair38";
  attribute SOFT_HLUTNM of \int_out_c[23]_i_1\ : label is "soft_lutpair38";
  attribute SOFT_HLUTNM of \int_out_c[24]_i_1\ : label is "soft_lutpair37";
  attribute SOFT_HLUTNM of \int_out_c[25]_i_1\ : label is "soft_lutpair37";
  attribute SOFT_HLUTNM of \int_out_c[26]_i_1\ : label is "soft_lutpair36";
  attribute SOFT_HLUTNM of \int_out_c[27]_i_1\ : label is "soft_lutpair36";
  attribute SOFT_HLUTNM of \int_out_c[28]_i_1\ : label is "soft_lutpair35";
  attribute SOFT_HLUTNM of \int_out_c[29]_i_1\ : label is "soft_lutpair35";
  attribute SOFT_HLUTNM of \int_out_c[2]_i_1\ : label is "soft_lutpair48";
  attribute SOFT_HLUTNM of \int_out_c[30]_i_1\ : label is "soft_lutpair34";
  attribute SOFT_HLUTNM of \int_out_c[31]_i_2\ : label is "soft_lutpair34";
  attribute SOFT_HLUTNM of \int_out_c[31]_i_3\ : label is "soft_lutpair0";
  attribute SOFT_HLUTNM of \int_out_c[3]_i_1\ : label is "soft_lutpair48";
  attribute SOFT_HLUTNM of \int_out_c[4]_i_1\ : label is "soft_lutpair47";
  attribute SOFT_HLUTNM of \int_out_c[5]_i_1\ : label is "soft_lutpair47";
  attribute SOFT_HLUTNM of \int_out_c[6]_i_1\ : label is "soft_lutpair46";
  attribute SOFT_HLUTNM of \int_out_c[7]_i_1\ : label is "soft_lutpair46";
  attribute SOFT_HLUTNM of \int_out_c[8]_i_1\ : label is "soft_lutpair45";
  attribute SOFT_HLUTNM of \int_out_c[9]_i_1\ : label is "soft_lutpair45";
begin
  \FSM_onehot_rstate_reg[1]_0\ <= \^fsm_onehot_rstate_reg[1]_0\;
  \FSM_onehot_wstate_reg[1]_0\ <= \^fsm_onehot_wstate_reg[1]_0\;
  \FSM_onehot_wstate_reg[2]_0\ <= \^fsm_onehot_wstate_reg[2]_0\;
  s_axi_control_BVALID <= \^s_axi_control_bvalid\;
  s_axi_control_RVALID <= \^s_axi_control_rvalid\;
\FSM_onehot_rstate[1]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"F747"
    )
        port map (
      I0 => s_axi_control_ARVALID,
      I1 => \^fsm_onehot_rstate_reg[1]_0\,
      I2 => \^s_axi_control_rvalid\,
      I3 => s_axi_control_RREADY,
      O => \FSM_onehot_rstate[1]_i_1_n_0\
    );
\FSM_onehot_rstate[2]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"8F88"
    )
        port map (
      I0 => s_axi_control_ARVALID,
      I1 => \^fsm_onehot_rstate_reg[1]_0\,
      I2 => s_axi_control_RREADY,
      I3 => \^s_axi_control_rvalid\,
      O => \FSM_onehot_rstate[2]_i_1_n_0\
    );
\FSM_onehot_rstate_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => '1',
      D => \FSM_onehot_rstate[1]_i_1_n_0\,
      Q => \^fsm_onehot_rstate_reg[1]_0\,
      R => ap_rst_n_inv
    );
\FSM_onehot_rstate_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => '1',
      D => \FSM_onehot_rstate[2]_i_1_n_0\,
      Q => \^s_axi_control_rvalid\,
      R => ap_rst_n_inv
    );
\FSM_onehot_wstate[1]_i_1\: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => ap_rst_n,
      O => ap_rst_n_inv
    );
\FSM_onehot_wstate[1]_i_2\: unisim.vcomponents.LUT5
    generic map(
      INIT => X"8F888FBB"
    )
        port map (
      I0 => s_axi_control_BREADY,
      I1 => \^s_axi_control_bvalid\,
      I2 => s_axi_control_AWVALID,
      I3 => \^fsm_onehot_wstate_reg[1]_0\,
      I4 => \^fsm_onehot_wstate_reg[2]_0\,
      O => \FSM_onehot_wstate[1]_i_2_n_0\
    );
\FSM_onehot_wstate[2]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"88F8"
    )
        port map (
      I0 => s_axi_control_AWVALID,
      I1 => \^fsm_onehot_wstate_reg[1]_0\,
      I2 => \^fsm_onehot_wstate_reg[2]_0\,
      I3 => s_axi_control_WVALID,
      O => \FSM_onehot_wstate[2]_i_1_n_0\
    );
\FSM_onehot_wstate[3]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"D5C0"
    )
        port map (
      I0 => s_axi_control_BREADY,
      I1 => \^fsm_onehot_wstate_reg[2]_0\,
      I2 => s_axi_control_WVALID,
      I3 => \^s_axi_control_bvalid\,
      O => \FSM_onehot_wstate[3]_i_1_n_0\
    );
\FSM_onehot_wstate_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => '1',
      D => \FSM_onehot_wstate[1]_i_2_n_0\,
      Q => \^fsm_onehot_wstate_reg[1]_0\,
      R => ap_rst_n_inv
    );
\FSM_onehot_wstate_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => '1',
      D => \FSM_onehot_wstate[2]_i_1_n_0\,
      Q => \^fsm_onehot_wstate_reg[2]_0\,
      R => ap_rst_n_inv
    );
\FSM_onehot_wstate_reg[3]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => '1',
      D => \FSM_onehot_wstate[3]_i_1_n_0\,
      Q => \^s_axi_control_bvalid\,
      R => ap_rst_n_inv
    );
\int_in_a[0]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(0),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[0]\,
      O => int_in_a0(0)
    );
\int_in_a[10]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(10),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[10]\,
      O => int_in_a0(10)
    );
\int_in_a[11]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(11),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[11]\,
      O => int_in_a0(11)
    );
\int_in_a[12]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(12),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[12]\,
      O => int_in_a0(12)
    );
\int_in_a[13]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(13),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[13]\,
      O => int_in_a0(13)
    );
\int_in_a[14]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(14),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[14]\,
      O => int_in_a0(14)
    );
\int_in_a[15]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(15),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[15]\,
      O => int_in_a0(15)
    );
\int_in_a[16]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(16),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[16]\,
      O => int_in_a0(16)
    );
\int_in_a[17]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(17),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[17]\,
      O => int_in_a0(17)
    );
\int_in_a[18]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(18),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[18]\,
      O => int_in_a0(18)
    );
\int_in_a[19]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(19),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[19]\,
      O => int_in_a0(19)
    );
\int_in_a[1]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(1),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[1]\,
      O => int_in_a0(1)
    );
\int_in_a[20]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(20),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[20]\,
      O => int_in_a0(20)
    );
\int_in_a[21]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(21),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[21]\,
      O => int_in_a0(21)
    );
\int_in_a[22]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(22),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[22]\,
      O => int_in_a0(22)
    );
\int_in_a[23]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(23),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_a_reg_n_0_[23]\,
      O => int_in_a0(23)
    );
\int_in_a[24]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(24),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[24]\,
      O => int_in_a0(24)
    );
\int_in_a[25]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(25),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[25]\,
      O => int_in_a0(25)
    );
\int_in_a[26]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(26),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[26]\,
      O => int_in_a0(26)
    );
\int_in_a[27]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(27),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[27]\,
      O => int_in_a0(27)
    );
\int_in_a[28]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(28),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[28]\,
      O => int_in_a0(28)
    );
\int_in_a[29]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(29),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[29]\,
      O => int_in_a0(29)
    );
\int_in_a[2]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(2),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[2]\,
      O => int_in_a0(2)
    );
\int_in_a[30]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(30),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[30]\,
      O => int_in_a0(30)
    );
\int_in_a[31]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"0800"
    )
        port map (
      I0 => s_axi_control_WVALID,
      I1 => \int_in_a[31]_i_3_n_0\,
      I2 => \waddr_reg_n_0_[3]\,
      I3 => \^fsm_onehot_wstate_reg[2]_0\,
      O => int_in_a
    );
\int_in_a[31]_i_2\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(31),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_a_reg_n_0_[31]\,
      O => int_in_a0(31)
    );
\int_in_a[31]_i_3\: unisim.vcomponents.LUT5
    generic map(
      INIT => X"00000002"
    )
        port map (
      I0 => \waddr_reg_n_0_[4]\,
      I1 => \waddr_reg_n_0_[1]\,
      I2 => \waddr_reg_n_0_[2]\,
      I3 => \waddr_reg_n_0_[0]\,
      I4 => \waddr_reg_n_0_[5]\,
      O => \int_in_a[31]_i_3_n_0\
    );
\int_in_a[3]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(3),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[3]\,
      O => int_in_a0(3)
    );
\int_in_a[4]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(4),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[4]\,
      O => int_in_a0(4)
    );
\int_in_a[5]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(5),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[5]\,
      O => int_in_a0(5)
    );
\int_in_a[6]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(6),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[6]\,
      O => int_in_a0(6)
    );
\int_in_a[7]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(7),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_a_reg_n_0_[7]\,
      O => int_in_a0(7)
    );
\int_in_a[8]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(8),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[8]\,
      O => int_in_a0(8)
    );
\int_in_a[9]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(9),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_a_reg_n_0_[9]\,
      O => int_in_a0(9)
    );
\int_in_a_reg[0]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(0),
      Q => \int_in_a_reg_n_0_[0]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[10]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(10),
      Q => \int_in_a_reg_n_0_[10]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[11]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(11),
      Q => \int_in_a_reg_n_0_[11]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[12]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(12),
      Q => \int_in_a_reg_n_0_[12]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[13]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(13),
      Q => \int_in_a_reg_n_0_[13]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[14]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(14),
      Q => \int_in_a_reg_n_0_[14]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[15]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(15),
      Q => \int_in_a_reg_n_0_[15]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[16]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(16),
      Q => \int_in_a_reg_n_0_[16]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[17]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(17),
      Q => \int_in_a_reg_n_0_[17]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[18]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(18),
      Q => \int_in_a_reg_n_0_[18]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[19]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(19),
      Q => \int_in_a_reg_n_0_[19]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(1),
      Q => \int_in_a_reg_n_0_[1]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[20]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(20),
      Q => \int_in_a_reg_n_0_[20]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[21]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(21),
      Q => \int_in_a_reg_n_0_[21]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[22]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(22),
      Q => \int_in_a_reg_n_0_[22]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[23]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(23),
      Q => \int_in_a_reg_n_0_[23]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[24]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(24),
      Q => \int_in_a_reg_n_0_[24]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[25]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(25),
      Q => \int_in_a_reg_n_0_[25]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[26]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(26),
      Q => \int_in_a_reg_n_0_[26]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[27]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(27),
      Q => \int_in_a_reg_n_0_[27]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[28]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(28),
      Q => \int_in_a_reg_n_0_[28]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[29]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(29),
      Q => \int_in_a_reg_n_0_[29]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(2),
      Q => \int_in_a_reg_n_0_[2]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[30]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(30),
      Q => \int_in_a_reg_n_0_[30]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[31]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(31),
      Q => \int_in_a_reg_n_0_[31]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[3]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(3),
      Q => \int_in_a_reg_n_0_[3]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[4]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(4),
      Q => \int_in_a_reg_n_0_[4]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[5]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(5),
      Q => \int_in_a_reg_n_0_[5]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[6]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(6),
      Q => \int_in_a_reg_n_0_[6]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[7]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(7),
      Q => \int_in_a_reg_n_0_[7]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[8]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(8),
      Q => \int_in_a_reg_n_0_[8]\,
      R => ap_rst_n_inv
    );
\int_in_a_reg[9]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_a,
      D => int_in_a0(9),
      Q => \int_in_a_reg_n_0_[9]\,
      R => ap_rst_n_inv
    );
\int_in_b[0]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(0),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[0]\,
      O => int_in_b0(0)
    );
\int_in_b[10]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(10),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[10]\,
      O => int_in_b0(10)
    );
\int_in_b[11]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(11),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[11]\,
      O => int_in_b0(11)
    );
\int_in_b[12]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(12),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[12]\,
      O => int_in_b0(12)
    );
\int_in_b[13]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(13),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[13]\,
      O => int_in_b0(13)
    );
\int_in_b[14]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(14),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[14]\,
      O => int_in_b0(14)
    );
\int_in_b[15]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(15),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[15]\,
      O => int_in_b0(15)
    );
\int_in_b[16]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(16),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[16]\,
      O => int_in_b0(16)
    );
\int_in_b[17]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(17),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[17]\,
      O => int_in_b0(17)
    );
\int_in_b[18]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(18),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[18]\,
      O => int_in_b0(18)
    );
\int_in_b[19]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(19),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[19]\,
      O => int_in_b0(19)
    );
\int_in_b[1]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(1),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[1]\,
      O => int_in_b0(1)
    );
\int_in_b[20]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(20),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[20]\,
      O => int_in_b0(20)
    );
\int_in_b[21]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(21),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[21]\,
      O => int_in_b0(21)
    );
\int_in_b[22]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(22),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[22]\,
      O => int_in_b0(22)
    );
\int_in_b[23]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(23),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_in_b_reg_n_0_[23]\,
      O => int_in_b0(23)
    );
\int_in_b[24]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(24),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[24]\,
      O => int_in_b0(24)
    );
\int_in_b[25]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(25),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[25]\,
      O => int_in_b0(25)
    );
\int_in_b[26]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(26),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[26]\,
      O => int_in_b0(26)
    );
\int_in_b[27]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(27),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[27]\,
      O => int_in_b0(27)
    );
\int_in_b[28]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(28),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[28]\,
      O => int_in_b0(28)
    );
\int_in_b[29]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(29),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[29]\,
      O => int_in_b0(29)
    );
\int_in_b[2]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(2),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[2]\,
      O => int_in_b0(2)
    );
\int_in_b[30]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(30),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[30]\,
      O => int_in_b0(30)
    );
\int_in_b[31]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"8000"
    )
        port map (
      I0 => s_axi_control_WVALID,
      I1 => \int_in_a[31]_i_3_n_0\,
      I2 => \waddr_reg_n_0_[3]\,
      I3 => \^fsm_onehot_wstate_reg[2]_0\,
      O => int_in_b
    );
\int_in_b[31]_i_2\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(31),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_in_b_reg_n_0_[31]\,
      O => int_in_b0(31)
    );
\int_in_b[3]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(3),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[3]\,
      O => int_in_b0(3)
    );
\int_in_b[4]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(4),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[4]\,
      O => int_in_b0(4)
    );
\int_in_b[5]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(5),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[5]\,
      O => int_in_b0(5)
    );
\int_in_b[6]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(6),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[6]\,
      O => int_in_b0(6)
    );
\int_in_b[7]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(7),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_in_b_reg_n_0_[7]\,
      O => int_in_b0(7)
    );
\int_in_b[8]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(8),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[8]\,
      O => int_in_b0(8)
    );
\int_in_b[9]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(9),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_in_b_reg_n_0_[9]\,
      O => int_in_b0(9)
    );
\int_in_b_reg[0]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(0),
      Q => \int_in_b_reg_n_0_[0]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[10]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(10),
      Q => \int_in_b_reg_n_0_[10]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[11]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(11),
      Q => \int_in_b_reg_n_0_[11]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[12]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(12),
      Q => \int_in_b_reg_n_0_[12]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[13]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(13),
      Q => \int_in_b_reg_n_0_[13]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[14]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(14),
      Q => \int_in_b_reg_n_0_[14]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[15]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(15),
      Q => \int_in_b_reg_n_0_[15]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[16]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(16),
      Q => \int_in_b_reg_n_0_[16]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[17]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(17),
      Q => \int_in_b_reg_n_0_[17]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[18]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(18),
      Q => \int_in_b_reg_n_0_[18]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[19]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(19),
      Q => \int_in_b_reg_n_0_[19]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(1),
      Q => \int_in_b_reg_n_0_[1]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[20]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(20),
      Q => \int_in_b_reg_n_0_[20]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[21]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(21),
      Q => \int_in_b_reg_n_0_[21]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[22]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(22),
      Q => \int_in_b_reg_n_0_[22]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[23]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(23),
      Q => \int_in_b_reg_n_0_[23]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[24]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(24),
      Q => \int_in_b_reg_n_0_[24]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[25]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(25),
      Q => \int_in_b_reg_n_0_[25]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[26]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(26),
      Q => \int_in_b_reg_n_0_[26]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[27]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(27),
      Q => \int_in_b_reg_n_0_[27]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[28]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(28),
      Q => \int_in_b_reg_n_0_[28]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[29]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(29),
      Q => \int_in_b_reg_n_0_[29]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(2),
      Q => \int_in_b_reg_n_0_[2]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[30]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(30),
      Q => \int_in_b_reg_n_0_[30]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[31]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(31),
      Q => \int_in_b_reg_n_0_[31]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[3]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(3),
      Q => \int_in_b_reg_n_0_[3]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[4]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(4),
      Q => \int_in_b_reg_n_0_[4]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[5]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(5),
      Q => \int_in_b_reg_n_0_[5]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[6]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(6),
      Q => \int_in_b_reg_n_0_[6]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[7]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(7),
      Q => \int_in_b_reg_n_0_[7]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[8]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(8),
      Q => \int_in_b_reg_n_0_[8]\,
      R => ap_rst_n_inv
    );
\int_in_b_reg[9]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_in_b,
      D => int_in_b0(9),
      Q => \int_in_b_reg_n_0_[9]\,
      R => ap_rst_n_inv
    );
\int_out_c[0]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(0),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[0]\,
      O => int_out_c0(0)
    );
\int_out_c[10]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(10),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[10]\,
      O => int_out_c0(10)
    );
\int_out_c[11]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(11),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[11]\,
      O => int_out_c0(11)
    );
\int_out_c[12]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(12),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[12]\,
      O => int_out_c0(12)
    );
\int_out_c[13]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(13),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[13]\,
      O => int_out_c0(13)
    );
\int_out_c[14]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(14),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[14]\,
      O => int_out_c0(14)
    );
\int_out_c[15]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(15),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[15]\,
      O => int_out_c0(15)
    );
\int_out_c[16]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(16),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[16]\,
      O => int_out_c0(16)
    );
\int_out_c[17]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(17),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[17]\,
      O => int_out_c0(17)
    );
\int_out_c[18]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(18),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[18]\,
      O => int_out_c0(18)
    );
\int_out_c[19]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(19),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[19]\,
      O => int_out_c0(19)
    );
\int_out_c[1]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(1),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[1]\,
      O => int_out_c0(1)
    );
\int_out_c[20]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(20),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[20]\,
      O => int_out_c0(20)
    );
\int_out_c[21]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(21),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[21]\,
      O => int_out_c0(21)
    );
\int_out_c[22]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(22),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[22]\,
      O => int_out_c0(22)
    );
\int_out_c[23]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(23),
      I1 => s_axi_control_WSTRB(2),
      I2 => \int_out_c_reg_n_0_[23]\,
      O => int_out_c0(23)
    );
\int_out_c[24]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(24),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[24]\,
      O => int_out_c0(24)
    );
\int_out_c[25]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(25),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[25]\,
      O => int_out_c0(25)
    );
\int_out_c[26]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(26),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[26]\,
      O => int_out_c0(26)
    );
\int_out_c[27]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(27),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[27]\,
      O => int_out_c0(27)
    );
\int_out_c[28]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(28),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[28]\,
      O => int_out_c0(28)
    );
\int_out_c[29]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(29),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[29]\,
      O => int_out_c0(29)
    );
\int_out_c[2]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(2),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[2]\,
      O => int_out_c0(2)
    );
\int_out_c[30]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(30),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[30]\,
      O => int_out_c0(30)
    );
\int_out_c[31]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000008000000000"
    )
        port map (
      I0 => s_axi_control_WVALID,
      I1 => \waddr_reg_n_0_[5]\,
      I2 => \int_out_c[31]_i_3_n_0\,
      I3 => \waddr_reg_n_0_[4]\,
      I4 => \waddr_reg_n_0_[3]\,
      I5 => \^fsm_onehot_wstate_reg[2]_0\,
      O => int_out_c
    );
\int_out_c[31]_i_2\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(31),
      I1 => s_axi_control_WSTRB(3),
      I2 => \int_out_c_reg_n_0_[31]\,
      O => int_out_c0(31)
    );
\int_out_c[31]_i_3\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"01"
    )
        port map (
      I0 => \waddr_reg_n_0_[1]\,
      I1 => \waddr_reg_n_0_[2]\,
      I2 => \waddr_reg_n_0_[0]\,
      O => \int_out_c[31]_i_3_n_0\
    );
\int_out_c[3]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(3),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[3]\,
      O => int_out_c0(3)
    );
\int_out_c[4]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(4),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[4]\,
      O => int_out_c0(4)
    );
\int_out_c[5]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(5),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[5]\,
      O => int_out_c0(5)
    );
\int_out_c[6]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(6),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[6]\,
      O => int_out_c0(6)
    );
\int_out_c[7]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(7),
      I1 => s_axi_control_WSTRB(0),
      I2 => \int_out_c_reg_n_0_[7]\,
      O => int_out_c0(7)
    );
\int_out_c[8]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(8),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[8]\,
      O => int_out_c0(8)
    );
\int_out_c[9]_i_1\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"B8"
    )
        port map (
      I0 => s_axi_control_WDATA(9),
      I1 => s_axi_control_WSTRB(1),
      I2 => \int_out_c_reg_n_0_[9]\,
      O => int_out_c0(9)
    );
\int_out_c_reg[0]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(0),
      Q => \int_out_c_reg_n_0_[0]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[10]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(10),
      Q => \int_out_c_reg_n_0_[10]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[11]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(11),
      Q => \int_out_c_reg_n_0_[11]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[12]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(12),
      Q => \int_out_c_reg_n_0_[12]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[13]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(13),
      Q => \int_out_c_reg_n_0_[13]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[14]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(14),
      Q => \int_out_c_reg_n_0_[14]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[15]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(15),
      Q => \int_out_c_reg_n_0_[15]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[16]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(16),
      Q => \int_out_c_reg_n_0_[16]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[17]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(17),
      Q => \int_out_c_reg_n_0_[17]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[18]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(18),
      Q => \int_out_c_reg_n_0_[18]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[19]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(19),
      Q => \int_out_c_reg_n_0_[19]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(1),
      Q => \int_out_c_reg_n_0_[1]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[20]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(20),
      Q => \int_out_c_reg_n_0_[20]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[21]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(21),
      Q => \int_out_c_reg_n_0_[21]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[22]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(22),
      Q => \int_out_c_reg_n_0_[22]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[23]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(23),
      Q => \int_out_c_reg_n_0_[23]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[24]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(24),
      Q => \int_out_c_reg_n_0_[24]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[25]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(25),
      Q => \int_out_c_reg_n_0_[25]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[26]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(26),
      Q => \int_out_c_reg_n_0_[26]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[27]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(27),
      Q => \int_out_c_reg_n_0_[27]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[28]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(28),
      Q => \int_out_c_reg_n_0_[28]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[29]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(29),
      Q => \int_out_c_reg_n_0_[29]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(2),
      Q => \int_out_c_reg_n_0_[2]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[30]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(30),
      Q => \int_out_c_reg_n_0_[30]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[31]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(31),
      Q => \int_out_c_reg_n_0_[31]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[3]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(3),
      Q => \int_out_c_reg_n_0_[3]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[4]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(4),
      Q => \int_out_c_reg_n_0_[4]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[5]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(5),
      Q => \int_out_c_reg_n_0_[5]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[6]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(6),
      Q => \int_out_c_reg_n_0_[6]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[7]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(7),
      Q => \int_out_c_reg_n_0_[7]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[8]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(8),
      Q => \int_out_c_reg_n_0_[8]\,
      R => ap_rst_n_inv
    );
\int_out_c_reg[9]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => ap_clk,
      CE => int_out_c,
      D => int_out_c0(9),
      Q => \int_out_c_reg_n_0_[9]\,
      R => ap_rst_n_inv
    );
\rdata[0]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[0]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[0]\,
      I4 => \int_out_c_reg_n_0_[0]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(0)
    );
\rdata[10]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[10]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[10]\,
      I4 => \int_out_c_reg_n_0_[10]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(10)
    );
\rdata[11]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[11]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[11]\,
      I4 => \int_out_c_reg_n_0_[11]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(11)
    );
\rdata[12]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[12]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[12]\,
      I4 => \int_out_c_reg_n_0_[12]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(12)
    );
\rdata[13]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[13]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[13]\,
      I4 => \int_out_c_reg_n_0_[13]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(13)
    );
\rdata[14]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[14]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[14]\,
      I4 => \int_out_c_reg_n_0_[14]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(14)
    );
\rdata[15]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[15]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[15]\,
      I4 => \int_out_c_reg_n_0_[15]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(15)
    );
\rdata[16]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[16]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[16]\,
      I4 => \int_out_c_reg_n_0_[16]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(16)
    );
\rdata[17]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[17]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[17]\,
      I4 => \int_out_c_reg_n_0_[17]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(17)
    );
\rdata[18]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[18]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[18]\,
      I4 => \int_out_c_reg_n_0_[18]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(18)
    );
\rdata[19]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[19]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[19]\,
      I4 => \int_out_c_reg_n_0_[19]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(19)
    );
\rdata[1]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[1]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[1]\,
      I4 => \int_out_c_reg_n_0_[1]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(1)
    );
\rdata[20]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[20]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[20]\,
      I4 => \int_out_c_reg_n_0_[20]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(20)
    );
\rdata[21]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[21]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[21]\,
      I4 => \int_out_c_reg_n_0_[21]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(21)
    );
\rdata[22]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[22]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[22]\,
      I4 => \int_out_c_reg_n_0_[22]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(22)
    );
\rdata[23]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[23]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[23]\,
      I4 => \int_out_c_reg_n_0_[23]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(23)
    );
\rdata[24]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[24]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[24]\,
      I4 => \int_out_c_reg_n_0_[24]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(24)
    );
\rdata[25]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[25]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[25]\,
      I4 => \int_out_c_reg_n_0_[25]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(25)
    );
\rdata[26]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[26]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[26]\,
      I4 => \int_out_c_reg_n_0_[26]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(26)
    );
\rdata[27]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[27]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[27]\,
      I4 => \int_out_c_reg_n_0_[27]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(27)
    );
\rdata[28]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[28]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[28]\,
      I4 => \int_out_c_reg_n_0_[28]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(28)
    );
\rdata[29]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[29]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[29]\,
      I4 => \int_out_c_reg_n_0_[29]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(29)
    );
\rdata[2]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[2]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[2]\,
      I4 => \int_out_c_reg_n_0_[2]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(2)
    );
\rdata[30]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[30]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[30]\,
      I4 => \int_out_c_reg_n_0_[30]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(30)
    );
\rdata[31]_i_1\: unisim.vcomponents.LUT2
    generic map(
      INIT => X"8"
    )
        port map (
      I0 => s_axi_control_ARVALID,
      I1 => \^fsm_onehot_rstate_reg[1]_0\,
      O => \rdata[31]_i_1_n_0\
    );
\rdata[31]_i_2\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[31]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[31]\,
      I4 => \int_out_c_reg_n_0_[31]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(31)
    );
\rdata[31]_i_3\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000100000000"
    )
        port map (
      I0 => s_axi_control_ARADDR(3),
      I1 => s_axi_control_ARADDR(1),
      I2 => s_axi_control_ARADDR(0),
      I3 => s_axi_control_ARADDR(2),
      I4 => s_axi_control_ARADDR(5),
      I5 => s_axi_control_ARADDR(4),
      O => \rdata[31]_i_3_n_0\
    );
\rdata[31]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000000000008"
    )
        port map (
      I0 => s_axi_control_ARADDR(3),
      I1 => s_axi_control_ARADDR(4),
      I2 => s_axi_control_ARADDR(5),
      I3 => s_axi_control_ARADDR(2),
      I4 => s_axi_control_ARADDR(0),
      I5 => s_axi_control_ARADDR(1),
      O => \rdata[31]_i_4_n_0\
    );
\rdata[31]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000000000000004"
    )
        port map (
      I0 => s_axi_control_ARADDR(4),
      I1 => s_axi_control_ARADDR(5),
      I2 => s_axi_control_ARADDR(3),
      I3 => s_axi_control_ARADDR(1),
      I4 => s_axi_control_ARADDR(0),
      I5 => s_axi_control_ARADDR(2),
      O => \rdata[31]_i_5_n_0\
    );
\rdata[3]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[3]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[3]\,
      I4 => \int_out_c_reg_n_0_[3]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(3)
    );
\rdata[4]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[4]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[4]\,
      I4 => \int_out_c_reg_n_0_[4]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(4)
    );
\rdata[5]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[5]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[5]\,
      I4 => \int_out_c_reg_n_0_[5]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(5)
    );
\rdata[6]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[6]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[6]\,
      I4 => \int_out_c_reg_n_0_[6]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(6)
    );
\rdata[7]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[7]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[7]\,
      I4 => \int_out_c_reg_n_0_[7]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(7)
    );
\rdata[8]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[8]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[8]\,
      I4 => \int_out_c_reg_n_0_[8]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(8)
    );
\rdata[9]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"FFFFF888F888F888"
    )
        port map (
      I0 => \rdata[31]_i_3_n_0\,
      I1 => \int_in_a_reg_n_0_[9]\,
      I2 => \rdata[31]_i_4_n_0\,
      I3 => \int_in_b_reg_n_0_[9]\,
      I4 => \int_out_c_reg_n_0_[9]\,
      I5 => \rdata[31]_i_5_n_0\,
      O => rdata(9)
    );
\rdata_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(0),
      Q => s_axi_control_RDATA(0),
      R => '0'
    );
\rdata_reg[10]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(10),
      Q => s_axi_control_RDATA(10),
      R => '0'
    );
\rdata_reg[11]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(11),
      Q => s_axi_control_RDATA(11),
      R => '0'
    );
\rdata_reg[12]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(12),
      Q => s_axi_control_RDATA(12),
      R => '0'
    );
\rdata_reg[13]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(13),
      Q => s_axi_control_RDATA(13),
      R => '0'
    );
\rdata_reg[14]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(14),
      Q => s_axi_control_RDATA(14),
      R => '0'
    );
\rdata_reg[15]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(15),
      Q => s_axi_control_RDATA(15),
      R => '0'
    );
\rdata_reg[16]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(16),
      Q => s_axi_control_RDATA(16),
      R => '0'
    );
\rdata_reg[17]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(17),
      Q => s_axi_control_RDATA(17),
      R => '0'
    );
\rdata_reg[18]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(18),
      Q => s_axi_control_RDATA(18),
      R => '0'
    );
\rdata_reg[19]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(19),
      Q => s_axi_control_RDATA(19),
      R => '0'
    );
\rdata_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(1),
      Q => s_axi_control_RDATA(1),
      R => '0'
    );
\rdata_reg[20]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(20),
      Q => s_axi_control_RDATA(20),
      R => '0'
    );
\rdata_reg[21]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(21),
      Q => s_axi_control_RDATA(21),
      R => '0'
    );
\rdata_reg[22]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(22),
      Q => s_axi_control_RDATA(22),
      R => '0'
    );
\rdata_reg[23]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(23),
      Q => s_axi_control_RDATA(23),
      R => '0'
    );
\rdata_reg[24]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(24),
      Q => s_axi_control_RDATA(24),
      R => '0'
    );
\rdata_reg[25]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(25),
      Q => s_axi_control_RDATA(25),
      R => '0'
    );
\rdata_reg[26]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(26),
      Q => s_axi_control_RDATA(26),
      R => '0'
    );
\rdata_reg[27]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(27),
      Q => s_axi_control_RDATA(27),
      R => '0'
    );
\rdata_reg[28]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(28),
      Q => s_axi_control_RDATA(28),
      R => '0'
    );
\rdata_reg[29]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(29),
      Q => s_axi_control_RDATA(29),
      R => '0'
    );
\rdata_reg[2]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(2),
      Q => s_axi_control_RDATA(2),
      R => '0'
    );
\rdata_reg[30]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(30),
      Q => s_axi_control_RDATA(30),
      R => '0'
    );
\rdata_reg[31]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(31),
      Q => s_axi_control_RDATA(31),
      R => '0'
    );
\rdata_reg[3]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(3),
      Q => s_axi_control_RDATA(3),
      R => '0'
    );
\rdata_reg[4]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(4),
      Q => s_axi_control_RDATA(4),
      R => '0'
    );
\rdata_reg[5]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(5),
      Q => s_axi_control_RDATA(5),
      R => '0'
    );
\rdata_reg[6]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(6),
      Q => s_axi_control_RDATA(6),
      R => '0'
    );
\rdata_reg[7]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(7),
      Q => s_axi_control_RDATA(7),
      R => '0'
    );
\rdata_reg[8]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(8),
      Q => s_axi_control_RDATA(8),
      R => '0'
    );
\rdata_reg[9]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => \rdata[31]_i_1_n_0\,
      D => rdata(9),
      Q => s_axi_control_RDATA(9),
      R => '0'
    );
\waddr[5]_i_1\: unisim.vcomponents.LUT2
    generic map(
      INIT => X"8"
    )
        port map (
      I0 => s_axi_control_AWVALID,
      I1 => \^fsm_onehot_wstate_reg[1]_0\,
      O => waddr
    );
\waddr_reg[0]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(0),
      Q => \waddr_reg_n_0_[0]\,
      R => '0'
    );
\waddr_reg[1]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(1),
      Q => \waddr_reg_n_0_[1]\,
      R => '0'
    );
\waddr_reg[2]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(2),
      Q => \waddr_reg_n_0_[2]\,
      R => '0'
    );
\waddr_reg[3]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(3),
      Q => \waddr_reg_n_0_[3]\,
      R => '0'
    );
\waddr_reg[4]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(4),
      Q => \waddr_reg_n_0_[4]\,
      R => '0'
    );
\waddr_reg[5]\: unisim.vcomponents.FDRE
     port map (
      C => ap_clk,
      CE => waddr,
      D => s_axi_control_AWADDR(5),
      Q => \waddr_reg_n_0_[5]\,
      R => '0'
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity bd_0_hls_inst_0_add is
  port (
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_AWREADY : out STD_LOGIC;
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_WREADY : out STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_ARREADY : out STD_LOGIC;
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_RVALID : out STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_BVALID : out STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC
  );
  attribute C_S_AXI_CONTROL_ADDR_WIDTH : integer;
  attribute C_S_AXI_CONTROL_ADDR_WIDTH of bd_0_hls_inst_0_add : entity is 6;
  attribute C_S_AXI_CONTROL_DATA_WIDTH : integer;
  attribute C_S_AXI_CONTROL_DATA_WIDTH of bd_0_hls_inst_0_add : entity is 32;
  attribute C_S_AXI_CONTROL_WSTRB_WIDTH : integer;
  attribute C_S_AXI_CONTROL_WSTRB_WIDTH of bd_0_hls_inst_0_add : entity is 4;
  attribute C_S_AXI_DATA_WIDTH : integer;
  attribute C_S_AXI_DATA_WIDTH of bd_0_hls_inst_0_add : entity is 32;
  attribute C_S_AXI_WSTRB_WIDTH : integer;
  attribute C_S_AXI_WSTRB_WIDTH of bd_0_hls_inst_0_add : entity is 4;
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of bd_0_hls_inst_0_add : entity is "add";
  attribute hls_module : string;
  attribute hls_module of bd_0_hls_inst_0_add : entity is "yes";
end bd_0_hls_inst_0_add;

architecture STRUCTURE of bd_0_hls_inst_0_add is
  signal \<const0>\ : STD_LOGIC;
begin
  s_axi_control_BRESP(1) <= \<const0>\;
  s_axi_control_BRESP(0) <= \<const0>\;
  s_axi_control_RRESP(1) <= \<const0>\;
  s_axi_control_RRESP(0) <= \<const0>\;
GND: unisim.vcomponents.GND
     port map (
      G => \<const0>\
    );
control_s_axi_U: entity work.bd_0_hls_inst_0_add_control_s_axi
     port map (
      \FSM_onehot_rstate_reg[1]_0\ => s_axi_control_ARREADY,
      \FSM_onehot_wstate_reg[1]_0\ => s_axi_control_AWREADY,
      \FSM_onehot_wstate_reg[2]_0\ => s_axi_control_WREADY,
      ap_clk => ap_clk,
      ap_rst_n => ap_rst_n,
      s_axi_control_ARADDR(5 downto 0) => s_axi_control_ARADDR(5 downto 0),
      s_axi_control_ARVALID => s_axi_control_ARVALID,
      s_axi_control_AWADDR(5 downto 0) => s_axi_control_AWADDR(5 downto 0),
      s_axi_control_AWVALID => s_axi_control_AWVALID,
      s_axi_control_BREADY => s_axi_control_BREADY,
      s_axi_control_BVALID => s_axi_control_BVALID,
      s_axi_control_RDATA(31 downto 0) => s_axi_control_RDATA(31 downto 0),
      s_axi_control_RREADY => s_axi_control_RREADY,
      s_axi_control_RVALID => s_axi_control_RVALID,
      s_axi_control_WDATA(31 downto 0) => s_axi_control_WDATA(31 downto 0),
      s_axi_control_WSTRB(3 downto 0) => s_axi_control_WSTRB(3 downto 0),
      s_axi_control_WVALID => s_axi_control_WVALID
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity bd_0_hls_inst_0 is
  port (
    s_axi_control_AWADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_AWVALID : in STD_LOGIC;
    s_axi_control_AWREADY : out STD_LOGIC;
    s_axi_control_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_control_WVALID : in STD_LOGIC;
    s_axi_control_WREADY : out STD_LOGIC;
    s_axi_control_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_BVALID : out STD_LOGIC;
    s_axi_control_BREADY : in STD_LOGIC;
    s_axi_control_ARADDR : in STD_LOGIC_VECTOR ( 5 downto 0 );
    s_axi_control_ARVALID : in STD_LOGIC;
    s_axi_control_ARREADY : out STD_LOGIC;
    s_axi_control_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_control_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_control_RVALID : out STD_LOGIC;
    s_axi_control_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of bd_0_hls_inst_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of bd_0_hls_inst_0 : entity is "bd_0_hls_inst_0,add,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of bd_0_hls_inst_0 : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of bd_0_hls_inst_0 : entity is "HLS";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of bd_0_hls_inst_0 : entity is "add,Vivado 2023.2";
  attribute hls_module : string;
  attribute hls_module of bd_0_hls_inst_0 : entity is "yes";
end bd_0_hls_inst_0;

architecture STRUCTURE of bd_0_hls_inst_0 is
  signal \<const0>\ : STD_LOGIC;
  signal NLW_inst_s_axi_control_BRESP_UNCONNECTED : STD_LOGIC_VECTOR ( 1 downto 0 );
  signal NLW_inst_s_axi_control_RRESP_UNCONNECTED : STD_LOGIC_VECTOR ( 1 downto 0 );
  attribute C_S_AXI_CONTROL_ADDR_WIDTH : integer;
  attribute C_S_AXI_CONTROL_ADDR_WIDTH of inst : label is 6;
  attribute C_S_AXI_CONTROL_DATA_WIDTH : integer;
  attribute C_S_AXI_CONTROL_DATA_WIDTH of inst : label is 32;
  attribute C_S_AXI_CONTROL_WSTRB_WIDTH : integer;
  attribute C_S_AXI_CONTROL_WSTRB_WIDTH of inst : label is 4;
  attribute C_S_AXI_DATA_WIDTH : integer;
  attribute C_S_AXI_DATA_WIDTH of inst : label is 32;
  attribute C_S_AXI_WSTRB_WIDTH : integer;
  attribute C_S_AXI_WSTRB_WIDTH of inst : label is 4;
  attribute SDX_KERNEL : string;
  attribute SDX_KERNEL of inst : label is "true";
  attribute SDX_KERNEL_SYNTH_INST : string;
  attribute SDX_KERNEL_SYNTH_INST of inst : label is "inst";
  attribute SDX_KERNEL_TYPE : string;
  attribute SDX_KERNEL_TYPE of inst : label is "hls";
  attribute X_INTERFACE_INFO : string;
  attribute X_INTERFACE_INFO of ap_clk : signal is "xilinx.com:signal:clock:1.0 ap_clk CLK";
  attribute X_INTERFACE_PARAMETER : string;
  attribute X_INTERFACE_PARAMETER of ap_clk : signal is "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF s_axi_control, ASSOCIATED_RESET ap_rst_n, FREQ_HZ 200000000.0, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN bd_0_ap_clk_0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of ap_rst_n : signal is "xilinx.com:signal:reset:1.0 ap_rst_n RST";
  attribute X_INTERFACE_PARAMETER of ap_rst_n : signal is "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of s_axi_control_ARREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARREADY";
  attribute X_INTERFACE_INFO of s_axi_control_ARVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARVALID";
  attribute X_INTERFACE_INFO of s_axi_control_AWREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWREADY";
  attribute X_INTERFACE_INFO of s_axi_control_AWVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWVALID";
  attribute X_INTERFACE_INFO of s_axi_control_BREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BREADY";
  attribute X_INTERFACE_INFO of s_axi_control_BVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BVALID";
  attribute X_INTERFACE_INFO of s_axi_control_RREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RREADY";
  attribute X_INTERFACE_PARAMETER of s_axi_control_RREADY : signal is "XIL_INTERFACENAME s_axi_control, ADDR_WIDTH 6, DATA_WIDTH 32, PROTOCOL AXI4LITE, READ_WRITE_MODE READ_WRITE, FREQ_HZ 200000000.0, ID_WIDTH 0, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 0, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.0, CLK_DOMAIN bd_0_ap_clk_0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of s_axi_control_RVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RVALID";
  attribute X_INTERFACE_INFO of s_axi_control_WREADY : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WREADY";
  attribute X_INTERFACE_INFO of s_axi_control_WVALID : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WVALID";
  attribute X_INTERFACE_INFO of s_axi_control_ARADDR : signal is "xilinx.com:interface:aximm:1.0 s_axi_control ARADDR";
  attribute X_INTERFACE_INFO of s_axi_control_AWADDR : signal is "xilinx.com:interface:aximm:1.0 s_axi_control AWADDR";
  attribute X_INTERFACE_INFO of s_axi_control_BRESP : signal is "xilinx.com:interface:aximm:1.0 s_axi_control BRESP";
  attribute X_INTERFACE_INFO of s_axi_control_RDATA : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RDATA";
  attribute X_INTERFACE_INFO of s_axi_control_RRESP : signal is "xilinx.com:interface:aximm:1.0 s_axi_control RRESP";
  attribute X_INTERFACE_INFO of s_axi_control_WDATA : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WDATA";
  attribute X_INTERFACE_INFO of s_axi_control_WSTRB : signal is "xilinx.com:interface:aximm:1.0 s_axi_control WSTRB";
begin
  s_axi_control_BRESP(1) <= \<const0>\;
  s_axi_control_BRESP(0) <= \<const0>\;
  s_axi_control_RRESP(1) <= \<const0>\;
  s_axi_control_RRESP(0) <= \<const0>\;
GND: unisim.vcomponents.GND
     port map (
      G => \<const0>\
    );
inst: entity work.bd_0_hls_inst_0_add
     port map (
      ap_clk => ap_clk,
      ap_rst_n => ap_rst_n,
      s_axi_control_ARADDR(5 downto 0) => s_axi_control_ARADDR(5 downto 0),
      s_axi_control_ARREADY => s_axi_control_ARREADY,
      s_axi_control_ARVALID => s_axi_control_ARVALID,
      s_axi_control_AWADDR(5 downto 0) => s_axi_control_AWADDR(5 downto 0),
      s_axi_control_AWREADY => s_axi_control_AWREADY,
      s_axi_control_AWVALID => s_axi_control_AWVALID,
      s_axi_control_BREADY => s_axi_control_BREADY,
      s_axi_control_BRESP(1 downto 0) => NLW_inst_s_axi_control_BRESP_UNCONNECTED(1 downto 0),
      s_axi_control_BVALID => s_axi_control_BVALID,
      s_axi_control_RDATA(31 downto 0) => s_axi_control_RDATA(31 downto 0),
      s_axi_control_RREADY => s_axi_control_RREADY,
      s_axi_control_RRESP(1 downto 0) => NLW_inst_s_axi_control_RRESP_UNCONNECTED(1 downto 0),
      s_axi_control_RVALID => s_axi_control_RVALID,
      s_axi_control_WDATA(31 downto 0) => s_axi_control_WDATA(31 downto 0),
      s_axi_control_WREADY => s_axi_control_WREADY,
      s_axi_control_WSTRB(3 downto 0) => s_axi_control_WSTRB(3 downto 0),
      s_axi_control_WVALID => s_axi_control_WVALID
    );
end STRUCTURE;