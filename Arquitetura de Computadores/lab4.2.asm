.data

Zero.s:     .word 0x00000000

PlusInf.s:  .word 0x7f800000

MinusInf.s: .word 0xff800000

PlusNaN.s:  .word 0x7f800020

MinusNaN.s: .word 0xff800002

Zero.d:     .word 0x00000000 0x00000000

PlusInf.d:  .word 0x00000000 0x7ff00000

MinusInf.d: .word 0x00000000 0xfff00000

PlusNaN.d:  .word 0x00000020 0x7ff00000

MinusNaN.d: .word 0x00000002 0xfff00000

MyNum.s: .word 0x41A00000



.text


lwc1 $f1,PlusInf.s #carrega o infinito em f1
mov.s $f12,$f1
li $v0,2
syscall

li $a0, '\n'  
li $v0, 11
syscall

lwc1 $f2,MyNum.s 
mov.s $f12,$f2
li $v0,2
syscall

li $a0, '\n'  
li $v0, 11
syscall

add.s $f4,$f1,$f2  #faz a soma entre eles e imprime
mov.s $f12,$f4
li $v0,2
syscall

li $a0, '\n' 
li $v0, 11
syscall

lwc1 $f6,PlusNaN.s  
add.s $f8,$f6,$f2    
mov.s $f12,$f8
li $v0,2
syscall             