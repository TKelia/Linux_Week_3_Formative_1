section .data
    welcome_msg     db "Welcome to ATM Simulator", 10, 0
    menu_msg        db "1. Deposit", 10, "2. Withdraw", 10, "3. Check Balance", 10, "4. Exit", 10, "Choose an option: ", 0
    deposit_msg     db "Enter deposit amount: ", 0
    withdraw_msg    db "Enter withdrawal amount: ", 0
    balance_msg     db "Current Balance: ", 0
    exit_msg        db "Thank you!", 10, 0
    invalid_msg     db "Invalid option!", 10, 0
    newline         db 10, 0

section .bss
    balance resd 1
    input   resb 10

section .text
    global _start

_start:
    mov dword [balance], 1000     ; initial balance

main_loop:
    call print_welcome
    call print_menu

    call read_choice
    cmp eax, 1
    je deposit
    cmp eax, 2
    je withdraw
    cmp eax, 3
    je check_balance
    cmp eax, 4
    je exit_program

    call print_invalid
    jmp main_loop

; ---------- Procedures ------------

print_welcome:
    mov eax, 4
    mov ebx, 1
    mov ecx, welcome_msg
    mov edx, 24
    int 0x80
    ret

print_menu:
    mov eax, 4
    mov ebx, 1
    mov ecx, menu_msg
    mov edx, 65
    int 0x80
    ret

print_invalid:
    mov eax, 4
    mov ebx, 1
    mov ecx, invalid_msg
    mov edx, 17
    int 0x80
    ret

read_choice:
    call read_input
    call atoi
    ret

deposit:
    mov eax, 4
    mov ebx, 1
    mov ecx, deposit_msg
    mov edx, 23
    int 0x80

    call read_input
    call atoi

    mov ebx, [balance]
    add ebx, eax
    mov [balance], ebx

    jmp main_loop

withdraw:
    mov eax, 4
    mov ebx, 1
    mov ecx, withdraw_msg
    mov edx, 25
    int 0x80

    call read_input
    call atoi

    mov ebx, [balance]
    sub ebx, eax
    mov [balance], ebx

    jmp main_loop

check_balance:
    mov eax, 4
    mov ebx, 1
    mov ecx, balance_msg
    mov edx, 17
    int 0x80

    mov eax, [balance]
    call print_int

    ; Print newline
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, 1
    int 0x80

    jmp main_loop

exit_program:
    mov eax, 4
    mov ebx, 1
    mov ecx, exit_msg
    mov edx, 14
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80

; ------------ Helper functions ------------

; read_input: read input from stdin into input buffer
read_input:
    mov eax, 3
    mov ebx, 0
    mov ecx, input
    mov edx, 10
    int 0x80
    ret

; atoi: convert ascii number in 'input' buffer to integer in eax
atoi:
    mov esi, input
    xor eax, eax
atoi_loop:
    movzx ecx, byte [esi]
    cmp ecx, 10        ; newline
    je atoi_done
    cmp ecx, '0'
    jl atoi_done
    cmp ecx, '9'
    jg atoi_done
    sub ecx, '0'
    imul eax, eax, 10
    add eax, ecx
    inc esi
    jmp atoi_loop
atoi_done:
    ret

; print_int: print integer in eax as decimal
print_int:
    mov ebx, 10
    xor ecx, ecx       ; digit count
    mov edi, input + 9 ; end of buffer
    mov byte [edi], 10 ; newline char
    dec edi

print_int_loop:
    xor edx, edx
    div ebx
    add dl, '0'
    mov [edi], dl
    dec edi
    inc ecx
    test eax, eax
    jnz print_int_loop

    inc edi
    mov eax, 4
    mov ebx, 1
    mov ecx, edi
    mov edx, ecx
    sub edx, edi
    add edx, ecx
    mov edx, ecx
    sub edx, edi
    inc edx
    int 0x80
    ret
