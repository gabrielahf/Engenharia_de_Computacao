library IEEE;
use IEEE.std_logic_1164.all;

entity soma_sub is
	port (a, b, Cin, m: in std_logic;
	      s, co: out std_logic);
end entity;

architecture a1 of soma_sub is
	signal bb: std_logic;
begin

    bb <= b xor m;
	co <= (a and bb) or (a and Cin) or (bb and Cin);
	s <= a xor bb xor Cin;
	
end architecture;