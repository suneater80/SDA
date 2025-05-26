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
    (*P)[5].ps_fs = 9;
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

    (*P)[9].info  = 'I';
    (*P)[9].ps_fs = 0;
    (*P)[9].ps_nb = 10;
    (*P)[9].ps_pr = 5;

    (*P)[10].info  = 'J';
    (*P)[10].ps_fs = 0;
    (*P)[10].ps_nb = 0;
    (*P)[10].ps_pr = 5;
}

boolean isEmpty(isi_Tree P)
{
    return(P[1].info == nil);
}

void preOrder(isi_Tree P){
    if (!isEmpty(P))
    {
        int pcur = 1;
        boolean resmi = true;
        
        printf("%c", P[pcur].info);
        do
        {
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

void inOrder(isi_Tree P){
    int pcur = 1;
    boolean resmi = true;
    if (isEmpty(P))
    {
        printf("Tree masih kosong\n");
        return;
    }

    while (pcur != 0)
    {
        if (P[pcur].ps_fs != 0 && resmi)
        {
            pcur = P[pcur].ps_fs;
        }else
        {
            if (resmi)
            {
                printf("%c", P[pcur].info);
            }
            if (pcur == P[P[pcur].ps_pr].ps_fs)
            {
                printf("%c", P[P[pcur].ps_pr].info);
            }
            if (P[pcur].ps_nb != 0)
            {
                pcur = P[pcur].ps_nb;
                resmi = true;
            }else
            {
                pcur = P[pcur].ps_pr;
                resmi = false;          //numpang lewat
            }
        }
    }
}

void postOrder(isi_Tree P){
    int pcur = 1;
    boolean resmi = false;
    if (isEmpty(P))
    {
        printf("Tree masih kosong\n");
        return;
    }
    while (pcur != 0)
    {
        if (P[pcur].ps_fs != 0 && !resmi)
        {
            pcur = P[pcur].ps_fs;            
        }
        else
        {
            printf("%c", P[pcur].info);

            if (P[pcur].ps_nb != 0)
            {
                pcur = P[pcur].ps_nb;
                resmi = false;          //numpang lewat

            }
            else 
            {
                pcur = P[pcur].ps_pr;   // ps.pr salah tulis tadi wkwkwk
                resmi = true;

            }
        }
    }
    
}
void levelOrder(isi_Tree P){
    Queue Q;
    Q.front = -1 ; Q.rear = -1;
    int pcur;
    printf("%c", P[1].info);
    pcur = P[1].ps_fs;
    while (pcur != 0)
    {
        printf("%c", P[pcur].info);
        if (P[pcur].ps_fs != 0)
        {
            Enqueue(&Q, P, &pcur);
        }
        if (P[pcur].ps_nb != 0)
        {
            pcur = P[pcur].ps_nb;
        }else {
            pcur = Q.data[(Q.front)];
            Dequeue(&Q);
            if (Q.front > Q.rear)
            {
                printf("nilai akhir front :%d\n", Q.front);
                printf("nilai akhir rear :%d\n", Q.rear);
                pcur = 0;
            }
        }
    }
}

void printTree(isi_Tree P){
    int i = 1;
    printf("Seluruh Node pada Non Binary Tree:\n");
    while (P[i].info != nil)
    {
        printf("\n");
        printf("--> Indeks ke-%d\n", i);
        printf("----------------------------------\n");
        printf("info array ke %d            : %c\n", i, P[i].info);
        printf("first son array ke %d       : %d\n", i, P[i].ps_fs);
        printf("next brother array ke %d    : %d\n", i, P[i].ps_nb);
        printf("parent array ke %d          : %d\n", i, P[i].ps_pr);
        printf("----------------------------------\n");
        printf("\n");
        i++;
    }
    
}

boolean search (isi_Tree P, infotype X){
    printf("Node yang akan dicari : ");
    scanf(" %c", &X);
    X = toupper(X);

    for (int i = 1; i < jml_maks; i++)
    {
        if (X == P[i].info)
        {
            printf("Node ada di dalam Tree");
            return(1);           
        }
    }
    printf("Node tidak ada di dalam Tree");
    return(0);

}

int level(isi_Tree P, int indeks_node){
     if (indeks_node == nil || indeks_node < 1 || indeks_node > jml_maks || P[indeks_node].info == nil) {
        return -1; 
    }
    int level = 0;
    int current = indeks_node;
    while (P[current].ps_pr != nil) {
        current = P[current].ps_pr;
        level++;
        if (current == nil || current < 1 || current > jml_maks) return -1; 
    }
    return level;
}
int nbDaun(isi_Tree P){
    if (isEmpty(P)) {
        printf("Tree kosong, tidak ada daun.\n");
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != nil) { 
            if (P[i].ps_fs == nil) 
            { 
                count++;
            }
        } else if (i > 1 && P[i-1].info == nil && P[1].info != nil) {

        }
    }
    return count;
}

int getLevelOfNodeByIndex(isi_Tree P, int node_idx) {
    if (node_idx == nil || node_idx < 1 || node_idx > jml_maks || P[node_idx].info == nil) {
        return -1; 
    }
    int level = 0;
    int current = node_idx;
    while (P[current].ps_pr != nil) {
        current = P[current].ps_pr;
        level++;
        if (current == nil || current < 1 || current > jml_maks) return -1; 
    }
    return level;
}

int findNodeByInfo(isi_Tree P, infotype X_cari) {
    X_cari = toupper(X_cari);
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info == X_cari) {
            return i; 
        }
         if (P[i].info == nil && i==1) return nil; 
    }
    return nil; 
}

int getLevelOfNodeByInfo(isi_Tree P, infotype X_cari) {
    printf("Masukkan info node yang ingin dicari levelnya: ");
    char char_input;
    scanf(" %c", &char_input);
    X_cari = toupper(char_input);

    int node_idx = findNodeByInfo(P, X_cari);
    if (node_idx == nil) {
        printf("Node '%c' tidak ditemukan.\n", X_cari);
        return -1;
    }
    return getLevelOfNodeByIndex(P, node_idx);
}

int depth(isi_Tree P){
    if (isEmpty(P)) {
        printf("Tree kosong \n");
        return -1;
    }
    int max_level = -1;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != nil) { 
            int current_level = getLevelOfNodeByIndex(P, i);
            if (current_level > max_level) {
                max_level = current_level;
            }
        } else if (i > 1 && P[i-1].info == nil && P[1].info != nil) {
            // break; // Optimization, see nbDaun
        }
    }
    return max_level;
}
boolean compareTree(isi_Tree P1, isi_Tree P2) {
    for (int i = 1; i <= jml_maks; i++) {
        if (P1[i].info != P2[i].info || P1[i].ps_fs != P2[i].ps_fs || P1[i].ps_nb != P2[i].ps_nb || P1[i].ps_pr != P2[i].ps_pr) {
            return false;
        }

    }

    return true;
}

void tampilkanBentukTree(isi_Tree P) {
    if (isEmpty(P)) {
        printf("Tree masih kosong.\n");
        return;
    }
    printf("Struktur Tree:\n");
    displayTreeStructureRecursive(P, 1, 0);
}

void displayTreeStructureRecursive(isi_Tree P, int node_idx, int indent) {
    if (node_idx == nil || P[node_idx].info == nil) {
        return;
    }

    // Print indentation
    for (int i = 0; i < indent; i++) {
        printf("  "); 
    }

    // Print node info
    printf("|- %c\n", P[node_idx].info);

    int current_child_idx = P[node_idx].ps_fs;
    while (current_child_idx != nil && P[current_child_idx].info != nil) {
        displayTreeStructureRecursive(P, current_child_idx, indent + 1);
        current_child_idx = P[current_child_idx].ps_nb; 
    }
}

//enqueue
void Dequeue(Queue *Q){
    if ((*Q).front == - 1 || (*Q).front > (*Q).rear)
    {
        printf("Underflow \n");
        return ;
    }else
    {
        (*Q).front = (*Q).front + 1;
    }
}
void Enqueue(Queue *Q, isi_Tree P, int *pcur){
    if ((*Q).rear == jml_maks - 1)
    {
        printf("Overflow \n");
    }else
    {
        if ((*Q).front == -1)
        {
            (*Q).front = 0;
        }
        (*Q).rear = (*Q).rear + 1;

        (*Q).data[(*Q).rear] = P[(*pcur)].ps_fs;
    }
}

void tampilkanMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrde\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n"); 
    printf("9.Kedalaman Tree\n");
    printf("10.membandingkan 2 node Tree\n");
    printf("11.Menampilkan bentuk Tree\n");
    printf("12.Exit\n");
    printf("Pilih menu: ");
}

#endif