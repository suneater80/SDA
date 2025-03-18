#ifndef Praktikum5_H
#define Praktikum5_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype info;
	 address  next;
} ElmtList;

typedef struct {
	address First;
} List;

/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L);

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L);

/**** Manajemen Memory ****/
address Alokasi (infotype X);

void DeAlokasi (address P);

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X);

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X);

void InsVLast (List * L, infotype X);

void InsertAfter(List *L, address P, address Prec);

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X);

void DelVLast (List * L, infotype * X);

void DelP(List *L, infotype X);

// untuk memprintf list
void PrintInfo(List L);


/* Delete semua elemen list dan alamat elemen di dealokasi */
void DelAll (List * L);

#endif