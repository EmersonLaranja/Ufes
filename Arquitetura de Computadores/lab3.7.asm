.data
a: .word 0 
b: .word 0
.text

li, $v0, 5
syscall
move, $t0, $v0
sw, $t0, a

li, $v0, 5
syscall
move, $t1, $v0
sw, $t1, b

divu $t3, $t0, $t1

mflo $t4
li, $v0, 1
move, $a0, $t4
syscall

li $a0, '\n'
li $v0, 11
syscall

mfhi $t5
li, $v0, 1
move, $a0, $t5
syscall