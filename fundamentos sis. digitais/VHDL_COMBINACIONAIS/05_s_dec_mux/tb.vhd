------------------------------------------------------------------------
--test bench para o somador / subtrator  com mux - Moraes - outubro 2020
------------------------------------------------------------------------
library ieee,work;
use ieee.std_logic_1164.all;

entity tb is
end;

architecture a1 of tb is 

   signal a,b, sum : std_logic_vector(7 downto 0);
   signal cout, ov  : std_logic;
   signal d  :  std_logic_vector(3 downto 0);
   signal mode  :  std_logic;

   type test_record is record
       a, b :  std_logic_vector(7 downto 0);
   end record;

   type padroes is array(natural range <>) of test_record;

   constant padrao_de_teste : padroes := (
        (a => x"44",  b => x"1F"),
        (a => x"54",  b => x"38")
      --  (a => x"78",  b => x"0F"),
      --  (a => x"22",  b => x"E5")
        );

   type t_oper is array(natural range <>) of integer;
   constant oper : t_oper := (0,1,2,3,4,5,6,7);

begin

    ex: entity work.s_dec_mux
             port map( a=> a, b=> b, mode=>mode, d=>d, S=> sum, cout=> cout, ov=>ov);   
   
    test: process
       variable idx : integer;
     begin       

      for md in 0 to 1 loop
        for op in 0 to 3 loop
          for i in 0 to padrao_de_teste'high loop
                b <= padrao_de_teste(i).b;
 
                case md is
                 when 0  =>        mode<='0';
                 when others =>    mode<='1';
                end case;    

                case op is
                 when 0  =>      d<="0001";
                 when 1  =>      d<="0010";
                 when 2  =>      d<="0100";
                 when others =>  d<="1000";
                end case;             

                a <= padrao_de_teste(i).a;
                b <= padrao_de_teste(i).b;

                wait for 10 ns;

           end loop;
        end loop;
     end loop;

        
    end process; 
        
end architecture;
