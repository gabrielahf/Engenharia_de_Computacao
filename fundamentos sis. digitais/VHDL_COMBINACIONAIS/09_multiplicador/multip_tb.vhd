------------------------------------------------------------------------
-- TestBench para o Multiplicador - Moraes - maio/2021 
-----------------------------------------------------------------------
library ieee,work;
use ieee.std_logic_1164.all;
use IEEE.std_logic_arith.CONV_STD_LOGIC_VECTOR;

entity tb is
end entity tb;

architecture tb of tb is 

   constant N  : natural := 8;        

   signal a    : std_logic_vector(N-1 downto 0);
   signal b    : std_logic_vector(N-1 downto 0);
   signal prod : std_logic_vector(N*2-1 downto 0);

   type test_record is record
       a, b :  integer;
   end record;

   type padroes is array(natural range <>) of test_record;

   constant padrao_de_teste : padroes := (
        (a =>  18,  b =>   33),  -- 594
        (a =>  40,  b =>   87),  -- 3480
        (a => 135,  b =>   24),  -- 3240
        (a => 241,  b =>   11),  -- 2651
        (a => 103,  b =>  200),  -- 20600
        (a =>  60,  b =>   75),  -- 4500
        (a => 255,  b =>  255),  -- 65025
        (a => 240,  b =>   15),  -- 3600
        (a =>  15,  b =>  255),  -- 3825
        (a =>   0,  b =>    0),  -- 0
        (a => 170,  b =>   99),  -- 16830
        (a =>  51,  b =>   23)   -- 1173 
    );

begin

    multiplicador:  entity work.multiplicador 
              generic map(N)
              port map( A=>a, B=>b, P=>prod);
       
    test: process
     begin       
        for i in 0 to padrao_de_teste'high loop     
                a <= CONV_STD_LOGIC_VECTOR(padrao_de_teste(i).a, a'length);
                b <= CONV_STD_LOGIC_VECTOR(padrao_de_teste(i).b, b'length);
                wait for 10 ns;
        end loop;

    end process; 

end architecture tb;

