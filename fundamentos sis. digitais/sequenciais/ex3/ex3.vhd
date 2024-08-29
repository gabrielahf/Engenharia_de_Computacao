-----**********************************************************
-----********************************************************** exercício 1
-----**********************************************************
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.Std_Logic_unsigned.all;

entity ex3 is
           port(  clock, reset : in std_logic;
                  saida : out STD_LOGIC_VECTOR (3 downto 0)  );
end ex3;

architecture a1 of ex3 is 
   signal R1, R2, soma: STD_LOGIC_VECTOR (3 downto 0);
begin

 process (clock, reset)
  begin
    if reset = '1' then
            R1 <= x"1";
            R2 <= x"0";
    elsif rising_edge(clock) then
            R1 <= soma;
            R2 <= R1;
    end if; 
 end process;

 soma <= R1 + R2;   

 saida <= soma;

end a1;

-----**********************************************************
-----**********************************************************   test bench	
-----**********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity tb is
end tb;

architecture arch of tb is
      signal reset: std_logic;
      signal ck : std_logic := '0' ;
      signal saida: STD_LOGIC_VECTOR(3 downto 0);
begin

      reset <= '1', '0' after 5 ns;

      ck <= not ck after 20 ns;

      ex1: entity work.ex3
          port map(clock => ck, reset => reset,  saida => saida);
          
end arch; 