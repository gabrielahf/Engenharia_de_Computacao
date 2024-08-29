library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity Circuito_seis is
    port (
        X, Y, Z: in std_logic_vector(7 downto 0);
        reset, clock, DS: in std_logic;
        mu: in std_logic_vector(1 downto 0);
        RB, RA: out std_logic_vector(7 downto 0)
    );
end Circuito_seis;

architecture Ex_seis of Circuito_seis is
    signal omux, R1, R2: std_logic_vector(7 downto 0);
    signal L1, L2: std_logic;

begin
    -- Decodificador 1:2
    process (DS)
    begin
        if DS = '0' then
            L1 <= '1';
            L2 <= '0';
        else
            L1 <= '0';
            L2 <= '1';
        end if;
    end process;

    -- Multiplexador 4:1
    process (X, Y, Z, R2, mu)
    begin
        case mu is
            when "00" =>
                omux <= X;
            when "01" =>
                omux <= Y;
            when "10" =>
                omux <= Z;
            when others =>
                omux <= R2;  -- Se mu não corresponder a nenhum caso, use R2.
        end case;
    end process;

    -- Registradores
    process (clock, reset)
    begin
        if reset = '1' then
            R1 <= (others => '0');
            R2 <= (others => '0');
        elsif rising_edge(clock) then
            R1 <= omux & L1;
            R2 <= R1 & L2;
        end if;
    end process;

    -- Saídas
    RA <= R1;
    RB <= R2;

end Ex_seis;
