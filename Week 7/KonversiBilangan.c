#include "konversiBilangan.h"

//stack baru
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

//isfull?
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

//isemptry?
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

//menambahkan elemen
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack penuh!\n");
        return;
    }
    stack->data[++stack->top] = value;
}

//mengeluarkan elemen
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

//konversi decimal->biner
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    Stack *stack = createStack(32); //ini untuk 32bit ya

    //sisa bagi disimpan ke staack
    while (decimal > 0) {
        push(stack, decimal % 2);
        decimal /= 2;
    }

    //mengeluarkan elemen untuk mendapat kan biner
    printf("Hasil konversi: ");
    while (!isEmpty(stack)) {
        printf("%d", pop(stack));
    }
    printf("\n");

    free(stack->data);
    free(stack);
}

int main() {
    int decimal;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    return 0;
}