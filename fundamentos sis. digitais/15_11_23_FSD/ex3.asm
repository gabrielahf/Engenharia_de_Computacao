#####################################################################
#   Exemplo de divisão de 10 por 3 usando subtrações sucessivas:
#   [Dividendo] [Divisor]  [Dividendo-Divisor]  Quociente 
#      10           3               7               1 
#       7           3               4               2 
#       4           3               1               3 
#      d1          d2             resto             q
#		1			3				-2
#####################################################################

.text
.globl main

main:  la $t0, d2
	   lw $t0, 0($t0)    	# carregamento do DIVISOR => $t0
	   la $t1, d1
	   lw $t1, 0($t1)    	# carregamento do DIVIDENDO => $t1
	   xor $t2, $t2, $t2 	# colocar zero no $t2 <= Q
	   
loop:  sub $t1, $t1, $t0 	# Dividendo-Divisor = $t1
	   blt $t1, $zero, fim  # $t1 (resto) < 0
	   addi $t2, $t2, 1		# Q++
	   j loop

fim:   add $t1, $t1, $t0    # restaurar o resto
	   la $t3, q 			# carregamos o endereço de Q
	   sw $t2, 0($t3)		# salva o conteudo de $t2 em Q
	   la $t3, resto        # carregamos o endereço do resto
	   sw $t1, 0($t3)		# salva o conteudo de $t1 em resto

end:   j end	

.data 
d1:    .word 0xFAAA  # 64170  resposta: 489 (1E9)  resto 111  (6F)
d2:    .word 0x83    # 131
q:     .word 0
resto: .word 0