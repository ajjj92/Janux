;;kernel.asm

;nasm directive - 32 bit, so kernel loads in 32-bit mode
bits 32
section .text
	;multiboot spec
	align 4
	dd 0x1BADB002					;Magic number->identify header
	dd 0x00							;flags
	dd - (0x1BADB002 + 0x00)		;checksum, must give zero

global start
extern kernelmain					;defined in C-file

start:
	cli								;block interrupt
	mov esp, stack_space			;stack pointer
	call kernelmain
	hlt							    ;halt cpu

	section .bss
	resb 8192						;give 8KB storage for stack
	stack_space:
