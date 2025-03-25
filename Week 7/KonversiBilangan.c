#include "konversiBilangan.h"

// Membuat stack baru
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Mengecek apakah stack penuh
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Mengecek apakah stack kosong
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Menambahkan elemen ke stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

// Mengeluarkan elemen dari stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Konversi desimal ke biner
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    Stack *stack = createStack(32); // Kapasitas stack untuk 32-bit

    // Simpan sisa bagi ke stack
    while (decimal > 0) {
        push(stack, decimal % 2);
        decimal /= 2;
    }

    // Keluarkan elemen stack untuk mendapatkan biner
    printf("Hasil konversi: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");

    free(stack->data);
    free(stack);
}

// Contoh penggunaan
int main() {
    int decimal;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}