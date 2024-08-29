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
-----  LATCH DE N BITS
-----**********************************************************
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity latch is
           generic(N : integer := 16);
           port(  ck, rst, ce : in std_logic;
                    D : in  STD_LOGIC_VECTOR (N-1 downto 0);
                    Q : out STD_LOGIC_VECTOR (N-1 downto 0)  );
end latch;

architecture a1 of latch is 
begin

  process(rst, ck, D)
  begin
       if rst = '1' then
                Q <= (others => '0');
       elsif ck='1' then
              if ce = '1' then
                Q <= D; 
              end if;
       end if;
  end process;      
end a1;



-----**********************************************************
-----**********************************************************
-----**********************************************************
library IEEE;
use IEEE.std_logic_1164.all;

entity tb is
end tb;

architecture arch of tb is
      signal reset, ce : std_logic;
      signal ck : std_logic := '0' ;
      signal D, q_ms, q_lt : STD_LOGIC_VECTOR(7 downto 0);
begin

      regMS: entity work.ffd_ms generic map(8)
          port map(ck => ck, rst => reset,  ce => ce, D => D, Q => q_ms);

      regLT: entity work.latch generic map(8)
          port map(ck => ck, rst => reset,  ce => ce, D => D, Q => q_lt);

      reset <= '1', '0' after 5 ns;

      ck <= not ck after 20 ns;

      ce <= '1', '0' after 50 ns, '1' after 80 ns;

      D <= x"AA", x"11" after 18 ns,  x"20" after 22 ns,  x"31" after 24 ns,  x"40" after 26 ns, x"51" after 30 ns,
                  x"60" after 34 ns,  x"71" after 36 ns,  x"80" after 45 ns,  x"91" after 48 ns, x"A0" after 58 ns,
                  x"B1" after 70 ns,  x"C0" after 75 ns,  x"D1" after 89 ns,  x"E0" after 90 ns, x"F1" after 110 ns,
                  x"00" after 170 ns, x"EE" after 230 ns;

end arch; 