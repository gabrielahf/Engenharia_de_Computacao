if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vcom -work work ex1.vhd

vsim -voptargs=+acc=lprn -t ns work.tb

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

add wave -noupdate /tb/reset
add wave -noupdate /tb/ck
add wave -noupdate /tb/ce
add wave -noupdate /tb/D
add wave -noupdate -divider {mestre-escravo}
add wave -noupdate /tb/q_ms
add wave -noupdate -divider {latch}
add wave -noupdate /tb/q_lt

run 300 ns

