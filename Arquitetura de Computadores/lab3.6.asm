.data
a: .word 0
b: .word 0

.text

li $v0, 5
syscall 
move $t0, $v0
sw $t0 a

li $v0, 5
syscall 
move $t1, $v0
sw $t1 b

mulu $t2,$t1,$t0
li $v0, 1
move $a0 $t2
syscall
