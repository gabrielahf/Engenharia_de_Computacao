library IEEE;
use IEEE.std_logic_1164.all;

entity tb is
end tb;

architecture tb of tb is
	signal rst, fin : std_logic := '0';
	signal fout : std_logic;
begin

	fin <= not fin after 10 ns;
	rst <= '1', '0' after 5 ns;

	dut: entity work.ex7  
	     port map(rst=>rst, fin => fin, fout => fout);

end tb; 
