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
	signal A, B : std_logic_vector(3 downto 0);
	signal S: std_logic_vector(3 downto 0);
	signal mode, cout, ov: std_logic := '0';
begin

	A <= x"A", x"F" after 20 ns, x"B" after 40 ns, x"7" after 60 ns, x"8" after 80 ns;
	B <= x"5", x"4" after 20 ns, x"C" after 40 ns, x"3" after 60 ns, x"8" after 80 ns;
    mode <= not mode after 10 ns;

	DUT: entity work.soma_sub4
	     port map(a=>A, b=>B, M=>mode, s=>S, CO=>cout, OV=>ov);

end architecture;

