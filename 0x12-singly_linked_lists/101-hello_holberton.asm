section .data
    message db 'Hello, Holberton', 10 ; 10 is the ASCII code for newline character

section .text
    global main

main:
    ; Display the message
    mov eax, 0        ; syscall number for sys_write
    mov edi, 1        ; file descriptor 1 (stdout)
    mov edx, 17       ; message length
    syscall          ; invoke syscall

    ; Exit the program
    mov eax, 60       ; syscall number for sys_exit
    xor edi, edi      ; exit code 0
    syscall          ; invoke syscall

