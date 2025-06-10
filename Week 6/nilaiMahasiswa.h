#ifndef NILAI_MAHASISWA_H
#define NILAI_MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define First(L) (L).first

//definisi tipe data untuk mahasiswa
typedef struct {
    char nama[30];
    int nilai;
} data;













//definisi node dan list
typedef struct Node *address;
typedef struct Node {
    data info;       //menyimpan data mahasiswa
    address next;    //pointer ke node berikutnya
} Node;

typedef struct {
    address first;   //pointer ke node pertama
} List;






















//                      MENGOLAH MEMORY
//alokasi memori untuk node baru
address alokasi(data N);

//membebaskan memori yang dialokasikan
void dealokasi(address P);

//                      FITUR LIST
//menampilkan isi list
void printList(List L);

//mencari elemen list berdasarkan nama
address search(List L, char *nama);

//menyalin elemen dari L1 ke L2 yang nilai > batas
void copyList(List L1, List *L2, int batas);

//menghapus duplikat berdasarkan nama (hanya menyisakan satu)
void removeDuplicate(List *L);

//mengurutkan data ascending berdasarkan nama
void sortByAscendNama(List *L);

//mengurutkan data descending berdasarkan nilai
void sortByDescendNilai(List *L);

//                      MENAMBAHKAN ELEMEN
//menambahkan elemen di awal
void insertFirst(List *L, data N);

//menambahkan elemen di akhir
void insertLast(List *L, data N);

//menambahkan elemen di tengah, sesuai urutan nama
void insertSorted(List *L, data N);

//                      MENGHAPUS ELEMEN
//menghapus seluruh elemen
void delAll(List *L);

#endif