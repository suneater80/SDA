#ifndef ANTRI_BANK_H
#define ANTRI_BANK_H

#include <stdio.h>
#include <stdlib.h>

//struktur node untuk Queue
typedef struct Node {
    int nomorAntrian;
    struct Node *next;
} Node;

//struktur queque
typedef struct {
    Node *front;
    Node *rear;
    int nextNumber;
} Queue;

//inisiasi queeu
void initQueue(Queue *q);

//menambahkan pelanggan
void enqueue(Queue *q);

//merespon pelanggan
void dequeue(Queue *q);

//cetak antrian
void printQueue(Queue *q);

#endif