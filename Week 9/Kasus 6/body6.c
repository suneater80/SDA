#include <stdio.h>
#include "header6.h"


void create_tree(isi_Tree X, int jml_Node)
{
    X[jml_Node];
    X[1].info  = 'A';
    X[1].ps_fs = 2;
    X[1].ps_nb = 0;
    X[1].ps_pr = 0;
    
    X[2].info  = 'B';
    X[2].ps_fs = 4;
    X[2].ps_nb = 3;
    X[2].ps_pr = 1;

    X[3].info  = 'C';
    X[3].ps_fs = 6;
    X[3].ps_nb = 0;
    X[3].ps_pr = 1;

    X[4].info  = 'D';
    X[4].ps_fs = 0;
    X[4].ps_nb = 5;
    X[4].ps_pr = 2;

    X[5].info  = 'E';
    X[5].ps_fs = 0;
    X[5].ps_nb = 0;
    X[5].ps_pr = 2;

    X[6].info  = 'F';
    X[6].ps_fs = 0;
    X[6].ps_nb = 7;
    X[6].ps_pr = 3;

    X[7].info  = 'G';
    X[7].ps_fs = 0;
    X[7].ps_nb = 8;
    X[7].ps_pr = 3;

    X[8].info  = 'H';
    X[8].ps_fs = 0;
    X[8].ps_nb = 0;
    X[8].ps_pr = 3;
}


boolean isEmpty(isi_Tree P)
{
    return(P[1].info == nil);
}

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
    printf("1. Input Data Tree");
    printf("2. Traversal PreOrder\n");
    printf("3. Traversal InOrder\n");
    printf("4. Traversal PostOrdet\n");
    printf("5. Traversal Level Order\n");
    printf("6. Print Tree\n");
    printf("7. Search node Tree\n");
    printf("8. Jumlah Daun/Leaf\n");
    printf("9. Mencari Level node Tree\n"); 
    printf("10.Kedalaman Tree\n");
    printf("11.membandingkan 2 node Tree");
    printf("12.Menampilkan bentuk Tree");
    printf("13.Exit");
    printf("Pilih menu: ");
}