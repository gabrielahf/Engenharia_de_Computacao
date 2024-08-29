onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider {entradas hexa}
add wave -noupdate -radix hexadecimal /tb/A
add wave -noupdate -radix hexadecimal /tb/B
add wave -noupdate -divider {entradas 2's}
add wave -noupdate -radix decimal /tb/DUT/a
add wave -noupdate -radix decimal /tb/DUT/b
add wave -noupdate /tb/DUT/M
add wave -noupdate -divider saidas
add wave -noupdate -radix hexadecimal /tb/S
add wave -noupdate -radix decimal -childformat {{/tb/DUT/s(3) -radix unsigned} {/tb/DUT/s(2) -radix unsigned} {/tb/DUT/s(1) -radix unsigned} {/tb/DUT/s(0) -radix unsigned}} -subitemconfig {/tb/DUT/s(3) {-radix unsigned} /tb/DUT/s(2) {-radix unsigned} /tb/DUT/s(1) {-radix unsigned} /tb/DUT/s(0) {-radix unsigned}} /tb/DUT/s
add wave -noupdate /tb/DUT/CO
add wave -noupdate /tb/DUT/OV
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {48 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
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
WaveRestoreZoom {0 ns} {120 ns}
