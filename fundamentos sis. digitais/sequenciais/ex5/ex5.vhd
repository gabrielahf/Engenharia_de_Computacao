library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity Circuito_cinco is
    port (
        X, Y: in std_logic_vector(7 downto 0);
        reset, clock, enableA, enableB: in std_logic;
        RA, RB: out std_logic_vector(7 downto 0)
    );
end Circuito_cinco;

architecture Ex_cinco of Circuito_cinco is
    signal xmux, ymux: std_logic_vector(7 downto 0);
    signal SA, SB: std_logic;

begin
    -- Multiplexador 2:1 para XMUX
process (X, REGB, SA)
begin
    if REGB = '0' then
        xmux <= X;
    else
        xmux <= REGB + SA;  -- A saída é a soma de REGB e SA se REGB não for zero.
    end if;
end process;


    -- Multiplexador 2:1 para YMUX
    process (REGA, Y, SB)
    begin
        if REGA = '0' then
            ymux <= Y;
        else
            ymux <= REGA + SB;
        end if;
    end process;

    -- Registrador REGA
    process (clock, reset, enableA, xmux)
    begin
        if reset = '1' then
            RA <= (others => '0');
        elsif rising_edge(clock) and enableA = '1' then
            RA <= xmux;
        end if;
    end process;

    -- Registrador REGB
    process (clock, reset, enableB, ymux)
    begin
        if reset = '1' then
            RB <= (others => '0');
        elsif rising_edge(clock) and enableB = '1' then
            RB <= ymux;
        end if;
    end process;

end Ex_cinco;
