#ifndef Body6_H
#define Body6_H
#include <stdio.h>
#include <string.h>
#include "header6.h"


void create_tree(isi_Tree *X, int jml_Node)
{
    for (int i = 1; i <= jml_Node; i++)
    {
        (*X)[i].info  = nil;
        (*X)[i].ps_fs = nil;
        (*X)[i].ps_nb = nil;
        (*X)[i].ps_pr = nil;   
    }
       
}
void pengisian_tree(isi_Tree *P){
    (*P)[1].info  = 'A';
    (*P)[1].ps_fs = 2;
    (*P)[1].ps_nb = 0;
    (*P)[1].ps_pr = 0;
    (*P)[2].info  = 'B';
    (*P)[2].ps_fs = 4;
    (*P)[2].ps_nb = 3;
    (*P)[2].ps_pr = 1;
    (*P)[3].info  = 'C';
    (*P)[3].ps_fs = 6;
    (*P)[3].ps_nb = 0;
    (*P)[3].ps_pr = 1;
    (*P)[4].info  = 'D';
    (*P)[4].ps_fs = 0;
    (*P)[4].ps_nb = 5;
    (*P)[4].ps_pr = 2;
    (*P)[5].info  = 'E';
    (*P)[5].ps_fs = 0;
    (*P)[5].ps_nb = 0;
    (*P)[5].ps_pr = 2;
    (*P)[6].info  = 'F';
    (*P)[6].ps_fs = 0;
    (*P)[6].ps_nb = 7;
    (*P)[6].ps_pr = 3;
    (*P)[7].info  = 'G';
    (*P)[7].ps_fs = 0;
    (*P)[7].ps_nb = 8;
    (*P)[7].ps_pr = 3;
    (*P)[8].info  = 'H';
    (*P)[8].ps_fs = 0;
    (*P)[8].ps_nb = 0;
    (*P)[8].ps_pr = 3;
}

boolean isEmpty(isi_Tree P)
{
    return(P[1].info == nil);
}

void preOrder(isi_Tree P){
    if (!isEmpty(P))
    {
        int pcur = 1;
        boolean resmi;
        
        printf("%c", P[pcur].info);
        resmi = true;
        do
        {
            printf("4\n");
            if (P[pcur].ps_fs != nil && resmi)
            {
                pcur = P[pcur].ps_fs;
                printf("%c", P[pcur].info);
            }else if (P[pcur].ps_nb != nil)
            {
                pcur = P[pcur].ps_nb;
                printf("%c", P[pcur].info);
                resmi = true;
            }else
            {
                pcur = P[pcur].ps_pr;
                resmi = false;          //numpang lewat dsini
            }
        } while (P[pcur].ps_pr != nil);
    }else printf("Tree masih kosong\n");
    
}

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
    printf("1. Input Data Tree\n");
    printf("2. Traversal PreOrder\n");
    printf("3. Traversal InOrder\n");
    printf("4. Traversal PostOrdet\n");
    printf("5. Traversal Level Order\n");
    printf("6. Print Tree\n");
    printf("7. Search node Tree\n");
    printf("8. Jumlah Daun/Leaf\n");
    printf("9. Mencari Level node Tree\n"); 
    printf("10.Kedalaman Tree\n");
    printf("11.membandingkan 2 node Tree\n");
    printf("12.Menampilkan bentuk Tree\n");
    printf("13.Exit\n");
    printf("Pilih menu: ");
}

#endif