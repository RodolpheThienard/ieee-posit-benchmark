-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
-- Date        : Mon Jul 22 11:30:23 2024
-- Host        : emg2abtics-virtual-machine running 64-bit Ubuntu 22.04.4 LTS
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_2_test_axi_entree_sort_0_0_stub.vhdl
-- Design      : design_2_test_axi_entree_sort_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xck26-sfvc784-2LV-c
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    aclk : in STD_LOGIC;
    aresetn : in STD_LOGIC;
    s_axis_tvalid_x : in STD_LOGIC;
    s_axis_tready_x : out STD_LOGIC;
    s_axis_tdata_x : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axis_tlast_x : in STD_LOGIC;
    m_axis_tvalid_r : out STD_LOGIC;
    m_axis_tready_r : in STD_LOGIC;
    m_axis_tdata_r : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axis_tlast_r : out STD_LOGIC
  );

end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "aclk,aresetn,s_axis_tvalid_x,s_axis_tready_x,s_axis_tdata_x[31:0],s_axis_tlast_x,m_axis_tvalid_r,m_axis_tready_r,m_axis_tdata_r[31:0],m_axis_tlast_r";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "test_axi_entree_sortie,Vivado 2023.2";
begin
end;
