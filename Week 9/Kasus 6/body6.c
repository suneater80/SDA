#include <stdio.h>
#include "header6.h"


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

void tampilkanMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrdet\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n"); 
    printf("9. Kedalaman Tree\n");
    printf("10.membandingkan 2 node Tree");
    printf("11.Exit");
    printf("Pilih menu: ");
}