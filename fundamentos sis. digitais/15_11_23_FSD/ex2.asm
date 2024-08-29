#main() {
#     int a[] = {0x123, 0x345, 0x879, 0x100, 0x090};
#     int max = 0, n = 5;
#     for(int i = 0; i < n; i++)  {
#          if (a[i] > max)
#          max = a[i];
.text
.globl main

main:  la  $t0, a		 #carreguei o endereço inicial (ponteiro) de a
	   xor $t1, $t1, $t1 # max <= 0 -- $t1 (max)
	   la  $t2, n		 # carreguei o endereço do n
	   lw  $t2, 0($t2)   # carreguei o valor de n
	   xor $t3, $t3, $t3 # i <= 0 -- $t3
	   
loop:  lw  $t4, 0($t0)   # $t4 <= a[i] 
	   blt $t4, $t1, naoconta 
	   add $t1, $t4, $zero  # $t1 <= $t4 --- max = a[i]

naoconta:
	   addi $t3, $t3, 1	# i++
	   addi $t0, $t0, 4 # incrementa o ponteiro para a proxima palavra
	   blt  $t3, $t2, loop
	   
	   la $t5, max		# carrega endereço de max
	   sw $t1, 0($t5)   # salva o valor calculado de max no endereço de max
	   
end:   j end

.data
max:   .word 0
n:     .word 5
a:     .word 0x123 0x345 0x879 0x100 0x900