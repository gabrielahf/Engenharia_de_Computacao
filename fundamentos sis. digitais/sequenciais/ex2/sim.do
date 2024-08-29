if {[file isdirectory work]} { vdel -all -lib work }
vlib work
vmap work work

vcom -work work ex2.vhd

vsim -voptargs=+acc=lprn -t ns work.tb

set StdArithNoWarnings 1
set StdVitalGlitchNoWarnings 1

add wave -noupdate /tb/reset
add wave -noupdate /tb/ck
add wave -noupdate -divider {entrada}
add wave -noupdate /tb/entrada
add wave -noupdate -divider {saida dos flip-flops}
add wave -noupdate /tb/A
add wave -noupdate /tb/B
add wave -noupdate /tb/C

run 300 ns

