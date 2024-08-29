-----**********************************************************
-----**********************************************************   test bench  
-----**********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity tb is
end tb;

architecture arch of tb is
      signal reset, send, req: std_logic;
      signal ck : std_logic := '0' ;
      signal entrada, saida: STD_LOGIC_VECTOR(3 downto 0);

      type padroes is array(natural range <>) of std_logic_vector(3 downto 0);

      constant padrao_de_teste : padroes := (
         x"1", x"2", x"3", x"4",
         x"5", x"6", x"7", x"8",
         x"3", x"4", x"4", x"5",
         x"2", x"1", x"1", x"3" );
begin

      reset <= '1', '0' after 3 ns;
      ck <= not ck after 5 ns;

      dut: entity work.ex8 
           port map(clock=>ck, reset=>reset, send=>send, req=>req,
               entrada=>entrada, saida=>saida);
                   
     test: process
     begin 

         send <= '0';
         req <= '0';

         wait for 100 ns;  

         -- envia as 4 palavras de 16 bits serialmente (de 4 em 4 bits) 
         for i in 0 to padrao_de_teste'high loop    
                entrada <= padrao_de_teste(i);
                send <= '1';
                wait for 10 ns;
                send <= '0';
                wait for 10 ns;
          end loop;

          wait for 60 ns;

          -- envia os 4 requests
          for i in 0 to 3 loop    
                req <= '1';
                wait for 10 ns;
                req <= '0';
                wait for 10 ns;
          end loop;

    end process; 


end arch; 