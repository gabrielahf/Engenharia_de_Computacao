--------------------------------------
-- Biblioteca
--------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use work.p_ula.all;

--------------------------------------
-- Entidade
--------------------------------------
entity alu is
  port(op1, op2 : in std_logic_vector(7 downto 0);
       opmode : in op_alu;
       z, cout, ov: out std_logic;
       outalu : out std_logic_vector(7 downto 0));
end entity;

--------------------------------------
-- Arquitetura
--------------------------------------
architecture alu of alu is
  signal aa, bb, soma: std_logic_vector(7 downto 0);
  signal mode: std_logic;
begin

  ----------------------------------
  -- Instancia o SomaSub
  ----------------------------------
  z <= '1' when soma = x"00" else '0';

  mode <= '0' when opmode=uADD or opmode=uINC or opmode=uDEC else '1';

  aa <= x"00" when opmode=uNEG else op1;
  
  bb <= x"01" when opmode=uINC else
        x"FF" when opmode=uDEC else 
        op1   when opmode=uNEG or opmode=uZero else
        op2;
        
  sb: entity work.soma_sub
    generic map(8)
    port map (a => aa, b => bb, mode => mode,
              S => soma, cout => cout, ov => ov);
 ----------------------------------
  -- ULA
  ----------------------------------
  outalu <= op1 and op2 when opmode=uAND else
            op1 or op2  when opmode=uOR else
            op1 xor op2 when opmode=uXOR else
            op1(6 downto 0) & '0' when opmode=uSLL else
            '0' & op1(7 downto 1) when opmode=uSRL else
            soma; --- uADD, uSUB, uINC, uNEG, DEC

end architecture;



