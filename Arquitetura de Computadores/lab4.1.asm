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


.text
main:

lwc1 $f0, Zero.s
mov.s $f12, $f0
li $v0, 2
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f1, PlusInf.s
mov.s $f12, $f1
li $v0, 2
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f2, MinusInf.s
mov.s $f12, $f2
li $v0, 2
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f3, PlusNaN.s
mov.s $f12, $f3
li $v0, 2
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f4, MinusNaN.s
mov.s $f12, $f4
li $v0, 2
syscall

li $a0, '\n'
li $v0, 11
syscall



li $a0, '\n'
li $v0, 11
syscall


lwc1 $f6, Zero.d
lwc1 $f7, Zero.d+4
mov.d $f12, $f6
li $v0, 3
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f8, PlusInf.d
lwc1 $f9, PlusInf.d+4
mov.d $f12, $f8
li $v0, 3
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f10, MinusInf.d
lwc1 $f11, MinusInf.d+4
mov.d $f12, $f10
li $v0, 3
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f14, PlusNaN.d
lwc1 $f15, PlusNaN.d+4
mov.d $f12, $f14
li $v0, 3
syscall

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f16, MinusNaN.d
lwc1 $f17, MinusNaN.d+4
mov.d $f12, $f16
li $v0, 3
syscall

li $a0, '\n'
li $v0, 11
syscall

j Exit


Exit: 