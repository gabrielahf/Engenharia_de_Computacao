--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

--------------------------------------
-- Entidade
--------------------------------------
entity soma_sub4 is
	port (a, b: in std_logic_vector(3 downto 0);
		  s:  out std_logic_vector(3 downto 0);
	      M:  in std_logic;
	      OV: out std_logic;
	      CO: out std_logic);
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture a1 of soma_sub4 is
	signal carry : std_logic_vector(4 downto 0);
begin

    carry(0) <= M;
	CO <= carry(4);
	OV <= carry(4) xor carry(3);

	FA1: entity work.soma_sub
		 port map (a=>a(0), b=>b(0), Cin=>carry(0), m=>M, s=>s(0), co=>carry(1));

	FA2: <completar>
		 
	FA3: <completar>

	FA4: <completar>
		 
end architecture a1;