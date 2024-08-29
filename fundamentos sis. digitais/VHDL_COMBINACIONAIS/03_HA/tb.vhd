--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

--------------------------------------
-- Entidade
--------------------------------------
entity tb is
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture tb of tb is
	signal A_tb, B_tb : std_logic;
	signal Sum_tb, Carry_tb : std_logic;
begin

	A_tb <= '0', '1' after 10 ns, '0' after 20 ns, '1' after 30 ns;
	
	B_tb <= '0', '1' after 20 ns;
	
	DUT: entity work.half_adder
	     port map(A => A_tb, B => B_tb, Sum => Sum_tb, Carry => Carry_tb);

end architecture;