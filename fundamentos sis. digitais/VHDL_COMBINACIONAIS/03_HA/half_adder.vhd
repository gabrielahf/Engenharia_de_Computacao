--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

--------------------------------------
-- Entidade
--------------------------------------
entity half_adder is
	port (A, B: in std_logic;
	      Sum, Carry: out std_logic);
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture half_adder of half_adder is
begin
	Sum   <= A xor B;	
	Carry <= A and B;
end architecture;