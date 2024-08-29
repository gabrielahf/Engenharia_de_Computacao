--********************************************************
-- EXERCICIO
--********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity s_dec_mux is
        port( A, B  : in  std_logic_vector(7 downto 0);   
              S     : out std_logic_vector(7 downto 0);   
              mode  : in  std_logic;          
              d     : in  std_logic_vector(3 downto 0);    
              cout  : out std_logic;            
              ov    : out std_logic            
         );
end entity;

architecture  a1 of  s_dec_mux is  
  signal sd : <completar> ;    -- saída do decoder
  signal bb : <completar> ;    -- saída do mux
begin                        
         
    sd <= <completar>

    bb <= <completar>

    sb: entity work.soma_sub
             generic map(8)
             port map(  <completar> );


end architecture a1;

