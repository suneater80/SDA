#ifndef Kasus6_H
#define Kasus6_H
#include <stdio.h>
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

typedef nbtree isi_Tree[jml_maks+1];

void create_tree(isi_Tree X, int jml_Node);
boolean isEmpty(isi_Tree P);

void preOrder(isi_Tree P);
void inOrder(isi_Tree P);
void postOrder(isi_Tree P);
void levelOrder(isi_Tree X, int maks_node);

void preintTree(isi_Tree P);
boolean search (isi_Tree P, infotype X);

int level(isi_Tree P, infotype X);
int nbDaun(isi_Tree P);
int depth(isi_Tree P);
int max(infotype data1, infotype data2);

void tampilkanMenu();

#endif