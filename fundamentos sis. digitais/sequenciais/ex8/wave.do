onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb/dut/clock
add wave -noupdate /tb/dut/reset
add wave -noupdate -divider entrada
add wave -noupdate /tb/dut/entrada
add wave -noupdate /tb/dut/send
add wave -noupdate -divider registradores
add wave -noupdate -color {Medium Violet Red} /tb/dut/A
add wave -noupdate -color {Medium Violet Red} /tb/dut/B
add wave -noupdate -color {Medium Violet Red} /tb/dut/C
add wave -noupdate -color {Medium Violet Red} /tb/dut/D
add wave -noupdate -color {Pale Green} /tb/dut/contIn
add wave -noupdate -divider soma
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {405 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {945 ns}
