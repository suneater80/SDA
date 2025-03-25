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

// Fungsi untuk inisialisasi stack
Stack* createStack(int capacity);

// Fungsi untuk mengecek apakah stack penuh
int isFull(Stack *stack);

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(Stack *stack);

// Fungsi untuk menambahkan elemen ke stack (push)
void push(Stack *stack, int value);

// Fungsi untuk mengeluarkan elemen dari stack (pop)
int pop(Stack *stack);

// Fungsi untuk mengonversi desimal ke biner
void decimalToBinary(int decimal);

#endif