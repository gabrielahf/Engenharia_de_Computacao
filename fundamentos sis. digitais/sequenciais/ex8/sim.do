if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vcom -work work ex8.vhd
vcom -work work ex8_tb.vhd

vsim -voptargs=+acc=lprn -t ns work.tb

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

do wave.do 

run 1500 ns

