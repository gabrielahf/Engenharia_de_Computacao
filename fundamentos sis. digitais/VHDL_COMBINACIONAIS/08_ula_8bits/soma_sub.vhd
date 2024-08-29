


--********************************************************
-- SOMADOR SUBRATOR DE N BITS
--********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity soma_sub is
        generic(N : integer := 4);  
        port( A, B  : in  std_logic_vector(N-1 downto 0); 
              S     : out std_logic_vector(N-1 downto 0); 
              mode  : in  std_logic;          --- modo            
              Cout  : out std_logic;            
              OV    : out std_logic            
         );
end entity;

architecture  a1 of  soma_sub is  
  signal co : std_logic_vector(N downto 0);
  signal bb : std_logic_vector(N-1 downto 0);
begin                
  co(0)   <= mode;          -- se o cin for 0 é soma, senão é subtração             
  Cout    <= co(N);          
  OV      <= co(N) xor co(N-1);          
         

  add: for i in 0 to N-1 generate       
    begin 
 
        bb(i)   <= b(i) xor mode;
        S(i)    <= co(i) xor A(i) xor bb(i);
        co(i+1) <= (co(i) and A(i)) or (co(i) and bb(i)) or (A(i) and bb(i));

    end generate;
end architecture a1;





