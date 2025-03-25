#ifndef ANTRI_BANK_H
#define ANTRI_BANK_H

#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Queue
typedef struct Node {
    int nomorAntrian;
    struct Node *next;
} Node;

// Struktur Queue
typedef struct {
    Node *front;
    Node *rear;
    int nextNumber;
} Queue;

// Fungsi untuk inisialisasi queue
void initQueue(Queue *q);

// Fungsi untuk menambahkan pelanggan ke antrian (enqueue)
void enqueue(Queue *q);

// Fungsi untuk memproses pelanggan (dequeue)
void dequeue(Queue *q);

// Fungsi untuk mencetak antrian
void printQueue(Queue *q);

#endif