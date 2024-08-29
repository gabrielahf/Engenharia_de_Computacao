if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vcom -work work ex3.vhd

vsim -voptargs=+acc=lprn -t ns work.tb

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

add wave -noupdate /tb/ex1/reset
add wave -noupdate /tb/ex1/clock
add wave -noupdate -divider {registradores}
add wave -noupdate /tb/ex1/R1
add wave -noupdate /tb/ex1/R2
add wave -noupdate -divider {saida}
add wave -noupdate /tb/saida

run 300 ns

