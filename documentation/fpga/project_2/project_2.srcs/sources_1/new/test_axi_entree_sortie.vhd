
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity test_axi_entree_sortie is
--  Port ( );
    port(
        -- Clock and Reset
        aclk : in std_logic;
        aresetn : in std_logic;

        -- AXI4-Stream Slave Interface (Input)
        s_axis_tvalid_x : in std_logic;
        s_axis_tready_x : out std_logic;
        s_axis_tdata_x : in std_logic_vector(31 downto 0);
        s_axis_tlast_x : in std_logic;

        -- AXI4-Stream Slave Interface (Input)
--        s_axis_tvalid_y : in std_logic;
--        s_axis_tready_y : out std_logic;
--        s_axis_tdata_y : in std_logic_vector(31 downto 0);
--        s_axis_tlast_y : in std_logic;

        -- AXI4-Stream Master Interface (Output)
        m_axis_tvalid_r : out std_logic;
        m_axis_tready_r : in std_logic;
        m_axis_tdata_r : out std_logic_vector(31 downto 0);
        m_axis_tlast_r : out std_logic 
        );
end test_axi_entree_sortie;

architecture Behavioral of test_axi_entree_sortie is

    signal s_tvalid_int : std_logic := '0';
    signal s_tdata_int: std_logic_vector(31 downto 0) := (others => '0');
    signal s_tlast_int : std_logic := '0'; 
    signal m_tready_int: std_logic := '0';

begin
    
process(aclk, aresetn)
    begin
        if aresetn = '0' then
            m_tready_int <= '0';
            s_tvalid_int <= '0';
            s_tdata_int <= (others => '0');
            s_tlast_int <= '0';
        elsif rising_edge(aclk) then
            if m_axis_tready_r = '1' and s_axis_tvalid_x = '1' then
                s_tvalid_int <= '1';
                m_tready_int <= '1';
                s_tdata_int <= s_axis_tdata_x;
                s_tlast_int <= s_axis_tlast_x;
            else 
                m_tready_int <= '0';  
                s_tvalid_int <= '0';
                s_tlast_int <= '0';    
            end if;
        end if;
    end process;
    
    s_axis_tready_x <= m_tready_int;
    m_axis_tvalid_r <= s_tvalid_int;
    m_axis_tlast_r <= s_tlast_int;
    m_axis_tdata_r <= s_tdata_int;

end Behavioral;
