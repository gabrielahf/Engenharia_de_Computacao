library ieee,work;
use ieee.std_logic_1164.all;
use IEEE.std_logic_arith.CONV_STD_LOGIC_VECTOR;

entity testa_soma is
end;

architecture a1 of testa_soma is 

   constant N  : natural := 12;         -- tamanho do somadores

   signal a, b, sum : std_logic_vector(N-1 downto 0);
   signal cout, mode, ov : std_logic;

   type test_record is record
       a, b :  integer;
       mode  :  std_logic;
   end record;

   type padroes is array(natural range <>) of test_record;

   constant padrao_de_teste : padroes := (
        (a => 234,  b => 890,  mode => '1'),
        (a => 234,  b => 890,  mode => '0'),
        (a => 89 ,  b => 630,  mode => '1'),
        (a => 89 ,  b => 630,  mode => '0'),
        (a => 999,  b => 710,  mode => '1'),
        (a => 999,  b => 710,  mode => '0'),
        (a => 12,   b => 501,  mode => '1'),
        (a => 12,   b => 501,  mode => '0'),
        (a => 123,  b => 432,  mode => '1'),
        (a => 123,  b => 432,  mode => '0'),
        (a => 345,  b => 323,  mode => '1'),
        (a => 345,  b => 323,  mode => '0'),
        (a => 888,  b => 121,  mode => '1'),
        (a => 888,  b => 121,  mode => '0'),
        (a => 100,  b => 900,  mode => '1'),
        (a => 100,  b => 900,  mode => '0'),
        (a => 300,  b => 124,  mode => '1'),
        (a => 300,  b => 124,  mode => '0')
    );
begin

    sb: entity work.soma_sub
             generic map(N)
             port map(a=>a, b=>b, mode=>mode, S=>sum, cout=>cout, ov=>ov);   
   
    test: process
     begin       

        for i in 0 to padrao_de_teste'high loop    
                a <= CONV_STD_LOGIC_VECTOR(padrao_de_teste(i).a, a'length);
                b <= CONV_STD_LOGIC_VECTOR(padrao_de_teste(i).b, b'length);
                mode <= padrao_de_teste(i).mode;
                wait for 10 ns;
        end loop;
        
    end process; 
        
end architecture;