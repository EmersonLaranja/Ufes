.data

dim: .word 2

#Z=8 , Y=1, X=8

a: .float 0.818 -1.188 

b: .float -2.881 3.818

r: .float 0 0

.text
li $t0, 0
li $t2, 4
lw $t4, dim

loop:
mul $t1, $t0, $t2
l.s  $f2, a($t1)
l.s  $f4, b($t1)

add.s  $f1, $f2, $f4
s.s $f1, r($t1)
addi $t0, $t0, 1
blt $t0, $t4, loop
