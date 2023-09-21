section .data
    format db "Hello, Holberton", 10, 0 ; 10 is the ASCII code for newline, 0 for null terminator

section .text
    global main
    extern printf

main:
    mov rdi, format      ; Load address of format string into rdi
    call printf          ; Call printf function

    ; Exit the program
    mov eax, 60          ; syscall number for sys_exit
    xor edi, edi         ; exit code 0
    syscall             ; invoke syscall

