onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /tb/ex/A
add wave -noupdate -radix hexadecimal /tb/ex/B
add wave -noupdate /tb/ex/mode
add wave -noupdate -radix hexadecimal /tb/ex/d
add wave -noupdate -divider saidas
add wave -noupdate -radix hexadecimal /tb/a
add wave -noupdate -radix hexadecimal /tb/ex/bb
add wave -noupdate -radix hexadecimal /tb/ex/S
add wave -noupdate /tb/ex/cout
add wave -noupdate /tb/ex/ov
add wave -noupdate -divider {sinais internos}
add wave -noupdate -radix hexadecimal /tb/ex/sd
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {324 ns} 0}
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
WaveRestoreZoom {0 ns} {210 ns}
