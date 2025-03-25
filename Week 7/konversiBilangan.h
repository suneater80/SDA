#ifndef KONVERSI_BILANGAN_H
#define KONVERSI_BILANGAN_H

#include <stdio.h>
#include <stdlib.h>

//struktur Stack
typedef struct Stack {
    int *data;
    int capacity;
    int top;
} Stack;

Stack* createStack(int capacity);

//apakah stack penuh?
int isFull(Stack *stack);

//apakah stack kosong?
int isEmpty(Stack *stack);

//menambah elemen stack
void push(Stack *stack, int value);

//mengeluarkan elemen dari stak
int pop(Stack *stack);

//konversi decimal->biner
void decimalToBinary(int decimal);

#endif