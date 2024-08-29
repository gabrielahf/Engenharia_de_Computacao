-----**********************************************************
-----  FLIP - FLOP MESTRE ESCRAVO DE N BITS
-----**********************************************************
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ffd_ms is
           generic(N : integer := 16);
           port(  ck, rst, ce : in std_logic;
                    D : in  STD_LOGIC_VECTOR (N-1 downto 0);
                    Q : out STD_LOGIC_VECTOR (N-1 downto 0)  );
end ffd_ms;

architecture a1 of ffd_ms is 
begin

  process(rst, ck)
  begin
       if rst = '1' then
                Q <= (others => '0');
       elsif rising_edge(ck) then
              if ce = '1' then
                Q <= D; 
              end if;
       end if;
  end process;      
end a1;

-----**********************************************************
-----**** REGISTRADOR DE DESLOCAMENTO
-----**********************************************************
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.Std_Logic_unsigned.all;

entity shift_reg is
           generic(N : integer := 8);
           port(  ck, rst : in std_logic;
                  entrada : in  STD_LOGIC_VECTOR (N-1 downto 0);
                  A, B, C : out STD_LOGIC_VECTOR (N-1 downto 0)  );
end shift_reg;

architecture a1 of shift_reg is 
   signal iA, iB, iC: STD_LOGIC_VECTOR (N-1 downto 0);
begin

 process (ck, rst)
  begin
    if rst = '1' then
            iA <= (others => '0');
            iB <= (others => '0');
            iC <= (others => '0');
      elsif rising_edge(ck) then
            iA <= entrada;
            iB <= iA;
            iC <= iB; 
    end if; 
 end process;

 C <= iC;
 B <= iB;
 A <= iA;

end a1;


-----**********************************************************
-----**********************************************************
-----**********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity tb is
end tb;

architecture arch of tb is
      signal reset : std_logic;
      signal ck : std_logic := '0' ;
      signal entrada, A, B, C : STD_LOGIC_VECTOR(7 downto 0);
begin


      shift1: entity work.shift_reg 
          generic map(8)
          port map(ck => ck, rst => reset,  entrada => entrada, A=>A, B=>B, C=>C);

      reset <= '1', '0' after 5 ns;

      ck <= not ck after 20 ns;

      entrada <=  x"12", x"23" after 40 ns,  x"37" after 80 ns,  x"48" after 120 ns,  x"5A" after 160 ns, x"63" after 200 ns;


end arch; 