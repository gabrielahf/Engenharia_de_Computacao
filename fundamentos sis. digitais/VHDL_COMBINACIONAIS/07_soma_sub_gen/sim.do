if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vcom -work work soma_sub4.vhd
vcom -work work tb.vhd

vsim -voptargs=+acc=lprn -t ns work.testa_soma

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

do wave_g.do 

run 800 ns

