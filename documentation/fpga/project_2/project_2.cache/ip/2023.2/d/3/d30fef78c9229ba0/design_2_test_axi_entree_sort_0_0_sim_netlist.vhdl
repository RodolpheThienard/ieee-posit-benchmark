-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2023.2 (lin64) Build 4029153 Fri Oct 13 20:13:54 MDT 2023
-- Date        : Mon Jul 22 11:30:24 2024
-- Host        : emg2abtics-virtual-machine running 64-bit Ubuntu 22.04.4 LTS
-- Command     : write_vhdl -force -mode funcsim -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_2_test_axi_entree_sort_0_0_sim_netlist.vhdl
-- Design      : design_2_test_axi_entree_sort_0_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xck26-sfvc784-2LV-c
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie is
  port (
    m_axis_tvalid_r : out STD_LOGIC;
    m_axis_tdata_r : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axis_tlast_r : out STD_LOGIC;
    aclk : in STD_LOGIC;
    s_axis_tdata_x : in STD_LOGIC_VECTOR ( 31 downto 0 );
    aresetn : in STD_LOGIC;
    s_axis_tvalid_x : in STD_LOGIC;
    m_axis_tready_r : in STD_LOGIC;
    s_axis_tlast_x : in STD_LOGIC
  );
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie is
  signal s_tlast_int : STD_LOGIC;
  signal s_tvalid_int0 : STD_LOGIC;
  signal s_tvalid_int_i_2_n_0 : STD_LOGIC;
begin
\s_tdata_int_reg[0]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(0),
      Q => m_axis_tdata_r(0)
    );
\s_tdata_int_reg[10]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(10),
      Q => m_axis_tdata_r(10)
    );
\s_tdata_int_reg[11]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(11),
      Q => m_axis_tdata_r(11)
    );
\s_tdata_int_reg[12]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(12),
      Q => m_axis_tdata_r(12)
    );
\s_tdata_int_reg[13]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(13),
      Q => m_axis_tdata_r(13)
    );
\s_tdata_int_reg[14]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(14),
      Q => m_axis_tdata_r(14)
    );
\s_tdata_int_reg[15]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(15),
      Q => m_axis_tdata_r(15)
    );
\s_tdata_int_reg[16]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(16),
      Q => m_axis_tdata_r(16)
    );
\s_tdata_int_reg[17]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(17),
      Q => m_axis_tdata_r(17)
    );
\s_tdata_int_reg[18]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(18),
      Q => m_axis_tdata_r(18)
    );
\s_tdata_int_reg[19]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(19),
      Q => m_axis_tdata_r(19)
    );
\s_tdata_int_reg[1]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(1),
      Q => m_axis_tdata_r(1)
    );
\s_tdata_int_reg[20]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(20),
      Q => m_axis_tdata_r(20)
    );
\s_tdata_int_reg[21]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(21),
      Q => m_axis_tdata_r(21)
    );
\s_tdata_int_reg[22]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(22),
      Q => m_axis_tdata_r(22)
    );
\s_tdata_int_reg[23]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(23),
      Q => m_axis_tdata_r(23)
    );
\s_tdata_int_reg[24]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(24),
      Q => m_axis_tdata_r(24)
    );
\s_tdata_int_reg[25]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(25),
      Q => m_axis_tdata_r(25)
    );
\s_tdata_int_reg[26]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(26),
      Q => m_axis_tdata_r(26)
    );
\s_tdata_int_reg[27]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(27),
      Q => m_axis_tdata_r(27)
    );
\s_tdata_int_reg[28]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(28),
      Q => m_axis_tdata_r(28)
    );
\s_tdata_int_reg[29]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(29),
      Q => m_axis_tdata_r(29)
    );
\s_tdata_int_reg[2]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(2),
      Q => m_axis_tdata_r(2)
    );
\s_tdata_int_reg[30]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(30),
      Q => m_axis_tdata_r(30)
    );
\s_tdata_int_reg[31]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(31),
      Q => m_axis_tdata_r(31)
    );
\s_tdata_int_reg[3]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(3),
      Q => m_axis_tdata_r(3)
    );
\s_tdata_int_reg[4]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(4),
      Q => m_axis_tdata_r(4)
    );
\s_tdata_int_reg[5]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(5),
      Q => m_axis_tdata_r(5)
    );
\s_tdata_int_reg[6]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(6),
      Q => m_axis_tdata_r(6)
    );
\s_tdata_int_reg[7]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(7),
      Q => m_axis_tdata_r(7)
    );
\s_tdata_int_reg[8]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(8),
      Q => m_axis_tdata_r(8)
    );
\s_tdata_int_reg[9]\: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => s_tvalid_int0,
      CLR => s_tvalid_int_i_2_n_0,
      D => s_axis_tdata_x(9),
      Q => m_axis_tdata_r(9)
    );
s_tlast_int_i_1: unisim.vcomponents.LUT3
    generic map(
      INIT => X"80"
    )
        port map (
      I0 => s_axis_tvalid_x,
      I1 => m_axis_tready_r,
      I2 => s_axis_tlast_x,
      O => s_tlast_int
    );
s_tlast_int_reg: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => '1',
      CLR => s_tvalid_int_i_2_n_0,
      D => s_tlast_int,
      Q => m_axis_tlast_r
    );
s_tvalid_int_i_1: unisim.vcomponents.LUT2
    generic map(
      INIT => X"8"
    )
        port map (
      I0 => m_axis_tready_r,
      I1 => s_axis_tvalid_x,
      O => s_tvalid_int0
    );
s_tvalid_int_i_2: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => aresetn,
      O => s_tvalid_int_i_2_n_0
    );
s_tvalid_int_reg: unisim.vcomponents.FDCE
    generic map(
      INIT => '0'
    )
        port map (
      C => aclk,
      CE => '1',
      CLR => s_tvalid_int_i_2_n_0,
      D => s_tvalid_int0,
      Q => m_axis_tvalid_r
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  port (
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
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "design_2_test_axi_entree_sort_0_0,test_axi_entree_sortie,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "yes";
  attribute IP_DEFINITION_SOURCE : string;
  attribute IP_DEFINITION_SOURCE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "module_ref";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix : entity is "test_axi_entree_sortie,Vivado 2023.2";
end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture STRUCTURE of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  signal \^m_axis_tvalid_r\ : STD_LOGIC;
  attribute X_INTERFACE_INFO : string;
  attribute X_INTERFACE_INFO of aclk : signal is "xilinx.com:signal:clock:1.0 aclk CLK";
  attribute X_INTERFACE_PARAMETER : string;
  attribute X_INTERFACE_PARAMETER of aclk : signal is "XIL_INTERFACENAME aclk, ASSOCIATED_BUSIF m_axis_r:s_axis_x, ASSOCIATED_RESET aresetn, FREQ_HZ 96968727, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of aresetn : signal is "xilinx.com:signal:reset:1.0 aresetn RST";
  attribute X_INTERFACE_PARAMETER of aresetn : signal is "XIL_INTERFACENAME aresetn, POLARITY ACTIVE_LOW, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of m_axis_tlast_r : signal is "xilinx.com:interface:axis:1.0 m_axis_r TLAST";
  attribute X_INTERFACE_PARAMETER of m_axis_tlast_r : signal is "XIL_INTERFACENAME m_axis_r, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 96968727, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, LAYERED_METADATA undef, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of m_axis_tready_r : signal is "xilinx.com:interface:axis:1.0 m_axis_r TREADY";
  attribute X_INTERFACE_INFO of m_axis_tvalid_r : signal is "xilinx.com:interface:axis:1.0 m_axis_r TVALID";
  attribute X_INTERFACE_INFO of s_axis_tlast_x : signal is "xilinx.com:interface:axis:1.0 s_axis_x TLAST";
  attribute X_INTERFACE_PARAMETER of s_axis_tlast_x : signal is "XIL_INTERFACENAME s_axis_x, TDATA_NUM_BYTES 4, TDEST_WIDTH 0, TID_WIDTH 0, TUSER_WIDTH 0, HAS_TREADY 1, HAS_TSTRB 0, HAS_TKEEP 0, HAS_TLAST 1, FREQ_HZ 96968727, PHASE 0.0, CLK_DOMAIN design_2_zynq_ultra_ps_e_0_0_pl_clk0, LAYERED_METADATA undef, INSERT_VIP 0";
  attribute X_INTERFACE_INFO of s_axis_tready_x : signal is "xilinx.com:interface:axis:1.0 s_axis_x TREADY";
  attribute X_INTERFACE_INFO of s_axis_tvalid_x : signal is "xilinx.com:interface:axis:1.0 s_axis_x TVALID";
  attribute X_INTERFACE_INFO of m_axis_tdata_r : signal is "xilinx.com:interface:axis:1.0 m_axis_r TDATA";
  attribute X_INTERFACE_INFO of s_axis_tdata_x : signal is "xilinx.com:interface:axis:1.0 s_axis_x TDATA";
begin
  m_axis_tvalid_r <= \^m_axis_tvalid_r\;
  s_axis_tready_x <= \^m_axis_tvalid_r\;
inst: entity work.decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_test_axi_entree_sortie
     port map (
      aclk => aclk,
      aresetn => aresetn,
      m_axis_tdata_r(31 downto 0) => m_axis_tdata_r(31 downto 0),
      m_axis_tlast_r => m_axis_tlast_r,
      m_axis_tready_r => m_axis_tready_r,
      m_axis_tvalid_r => \^m_axis_tvalid_r\,
      s_axis_tdata_x(31 downto 0) => s_axis_tdata_x(31 downto 0),
      s_axis_tlast_x => s_axis_tlast_x,
      s_axis_tvalid_x => s_axis_tvalid_x
    );
end STRUCTURE;
