-------------------------------------------------------------------------------
-- FERNANDO MORAES - multiplicador array  -   revisado em maio/2021
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
--  somador série com and em 'b' e cin='0'
-------------------------------------------------------------------------------                                
library IEEE;
use IEEE.std_logic_1164.all;

entity somador_serie is
        generic(N : integer := 8);  
        port(   prev_sum, b  : in  std_logic_vector(N-1 downto 0);  
                a            : in  std_logic;
                sum          : out std_logic_vector(N downto 0)
             );
end entity;

architecture a1 of  somador_serie is
   signal co: std_logic_vector(N downto 0);  
   signal bb : std_logic_vector(N-1 downto 0);
begin       

   co(0)   <= '0';                 
   sum(N)  <= co(N);

   add:  for i in 0  to N-1  generate
        bb(i)   <= b(i) and a;
        sum(i)  <= co(i) xor prev_sum(i) xor bb(i);
        co(i+1) <= (co(i) and prev_sum(i)) or (co(i) and bb(i)) or (prev_sum(i) and bb(i));
   end generate add;

end a1;

-------------------------------------------------------------------------------
-- MULTIPLICADOR  
-------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity multiplicador is        
        generic(N : integer := 4);  
        port(   A : in  std_logic_vector(N-1 downto 0);
                B : in  std_logic_vector(N-1 downto 0);
                P : out std_logic_vector(N*2-1 downto 0)
            );
end entity;

architecture multiplicador of  multiplicador is
        type   matriz is array(0 to N-1) of std_logic_vector(N downto 0);
        signal sum : matriz;
begin 
   
   -- primeira camada da multiplicação - só ands
   soma0:  for i in 0  to N-1  generate
        sum(0)(i) <= a(0) and b(i);
   end generate soma0;
   sum(0)(N) <= '0';   
           
   linhas:  for i in 1 to N-1  generate   
 
      s: entity work.somador_serie port map( prev_sum=> sum(i-1)(N downto 1),  b=>b, a=>a(i),  
                                             sum => sum(i) );
   end generate linhas;   

   pp:  for i in 0  to N-1  generate   -- resultado
        P(i) <= sum(i)(0);
        P(i+N) <= sum(N-1)(i+1);
   end generate pp;  

end multiplicador;