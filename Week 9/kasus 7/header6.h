#ifndef Header6_H
#define Header6_H
#include <stdio.h>
#include <ctype.h>
#include "BOOLEAN.H"

#define jml_maks 20     //maksimal node yang dapat ditampung
#define kebawah 1
#define keatas  2
#define kekanan 3
#define nil     0

typedef char infotype;
typedef int address;
typedef struct
{
    infotype info;
    address ps_fs;
    address ps_nb;
    address ps_pr;
}nbtree;

typedef struct 
{
    int front;
    int rear;
    int data[jml_maks];
}Queue;

typedef nbtree isi_Tree[jml_maks+1];

void create_tree(isi_Tree *P, int jml_Node);
void pengisian_tree(isi_Tree *P);
boolean isEmpty(isi_Tree P);

void preOrder(isi_Tree P);
void inOrder(isi_Tree P);
void postOrder(isi_Tree P);
void levelOrder(isi_Tree P);

void printTree(isi_Tree P);
boolean search (isi_Tree P, infotype X);

int level(isi_Tree P, int node_idx);
int nbDaun(isi_Tree P);
int depth(isi_Tree P);
boolean compareTree(isi_Tree P1, isi_Tree P2);
int getLevelOfNodeByIndex(isi_Tree P, int node_idx);
int getLevelOfNodeByInfo(isi_Tree P, infotype X_cari);
int findNodeByInfo(isi_Tree P, infotype X_cari);

//Queue
boolean isEmptyQueue(Queue Q);
void Dequeue(Queue *Q);
void Enqueue(Queue *Q, isi_Tree P, int *pcur);

void tampilkanMenu();

#endif