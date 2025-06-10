#ifndef Header9_H
#define Header9_H
#include <stdio.h>
#include <ctype.h>  
#include <stdlib.h>
#include <string.h>
#include "BOOLEAN.H"
#define nil     NULL

typedef struct morse *address;
typedef struct morse
{
    char info;
    address L_ptr;
    address R_ptr;
}btree;


typedef struct QueueNode {
    address treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;


void createRoot(address *root);
address createNode(char info);
void freeTree(address node);
void pengisian_tree(address root);

void insertMorse(address root, const char *path, char value);
void inOrder(address root);
void levelOrder(address root);

char* stringToMorse(address root, const char *text);
char* morseToString(address root, const char *morseCode);


void tampilkanMenu();

#endif