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
	signal A, B, Cin : std_logic;
	signal Cout, Soma : std_logic;
begin

	A <= '0', '1' after 10 ns, '0' after 20 ns, '1' after 30 ns, '0' after 40 ns, '1' after 50 ns, '0' after 60 ns, '1' after 70 ns;
	
	B <= '0', '1' after 20 ns, '0' after 40 ns, '1' after 60 ns;
	
	Cin <= '0', '1' after 40 ns;

	DUT: entity work.full_adder
	     port map(A => A, B => B, Cin => Cin, Cout => Cout, Soma => Soma);

end architecture;