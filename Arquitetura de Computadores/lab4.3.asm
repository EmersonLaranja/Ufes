.data
msg: .asciiz  "O valor de entrada deve ser positivo"

.text 

LeInteiro:
li $v0, 5
syscall 

move $t0 $v0
move $t2, $t0

slt $t1,$t0,$zero
beq $t1, 1, ImprimeErro


Fatorial:

beq $t0, 0, PrintOne
beq $t0, 1, ImprimeResultado

sub $t0, $t0, 1
mul $t2, $t2, $t0

jal Fatorial

PrintOne:
li  $v0, 1
addi $t2, $zero, 1
mtc1 $t2, $f0
cvt.s.w $f0, $f0
mov.s  $f12, $f0
li $v0, 2
syscall
jal Exit

ImprimeResultado: 

mtc1 $t2, $f0
cvt.s.w $f0, $f0
mov.s  $f12, $f0
li $v0, 2

syscall
jal Exit

ImprimeErro:
la $a0,msg
li $v0,4
syscall
jal LeInteiro

Exit: