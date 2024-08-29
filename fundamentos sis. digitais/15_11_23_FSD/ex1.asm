.text
.globl main

main:  xor $s3, $s3, $s3   # zerar o registrador que contem o "i"
       la  $s5, k	   	   # endereço de "k" carregado em s5
       lw  $s5, 0($s5)      # carrego o dado de "k" 0x100
       la  $s6, save       # endereço de "save" carregado em s6

Loop:  sll  $t1, $s3, 2    # $t1 = i * 4 : para endereÃ§ar save
       add  $t1, $t1, $s6  # $t1 = address of save[i] 
       lw   $t0, 0($t1)    # $t0 = save[i]  
       beq  $t0, $s5, Exit # go to Exit if save[i] = k
       addi $s3, $s3, 1    # i = i + 1
       j    Loop           # go to Loop

Exit:  la $s7, pos 		   # carreguei o endereço de "pos"
	   sw $s3, 0($s7)      # salvar o "i" no endereço de "pos" "pos <= i"

fim:   j    fim

.data
k:     .word 0x100
pos:   .word 0
save:  .word 0x901 0x345 0x879 0x100 0x900
