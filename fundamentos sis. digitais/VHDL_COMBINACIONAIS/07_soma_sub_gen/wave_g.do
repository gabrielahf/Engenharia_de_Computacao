onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -divider {entradas hexa}
add wave -noupdate -radix unsigned /testa_soma/sb/A
add wave -noupdate -radix unsigned /testa_soma/sb/B
add wave -noupdate /testa_soma/sb/mode
add wave -noupdate -divider saidas
add wave -noupdate -radix unsigned /testa_soma/sb/S
add wave -noupdate /testa_soma/cout
add wave -noupdate /testa_soma/ov
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {30 ns} 0}
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
WaveRestoreZoom {0 ns} {800 ns}
