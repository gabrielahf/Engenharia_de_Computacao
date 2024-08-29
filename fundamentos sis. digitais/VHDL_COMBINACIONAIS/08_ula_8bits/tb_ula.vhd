------------------------------------------------------------------------
-- verificação da ULA
-- Fernando Moraes
------------------------------------------------------------------------
library ieee,work;
use ieee.std_logic_1164.all;
use work.p_ula.all;

entity tb is
end tb;

architecture a1 of tb is 

   signal op1, op2, outalu : std_logic_vector(7 downto 0);
   signal z, cout, ov  : std_logic;
   signal opmode : op_alu;

   type test_record is record
       a, b :  std_logic_vector(7 downto 0);
   end record;

   type padroes is array(natural range <>) of test_record;

   constant padrao_de_teste : padroes := (
        (a => x"AA",  b => x"55"),
        (a => x"FF",  b => x"FF"),
        (a => x"34",  b => x"00"),
        (a => x"00",  b => x"22"),
        (a => x"56",  b => x"01"),
        (a => x"05",  b => x"0A")
    );

 begin

    sb: entity work.alu
             port map( op1=> op1, op2=> op2, outalu=>outalu, z=>z, cout=>cout, ov=>ov, opmode=>opmode);   
   
    test: process
     begin       

      for op in op_alu loop    --  percorre o tipo enumerado

            opmode <= op;         

            for i in 0 to padrao_de_teste'high loop    
                op1 <= padrao_de_teste(i).a;
                op2 <= padrao_de_teste(i).b;
                wait for 10 ns;
            end loop;

    end loop;
     
    end process; 
        
end architecture;

