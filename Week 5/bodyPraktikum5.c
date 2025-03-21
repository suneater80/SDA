#include <limits.h>
#include <malloc.h>
#include "Praktikum5.h"
#define bodyPraktikum5_c

void CreateList (List * L)
{
	 First(*L) = Nil;
}

boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	 return (First(L) == Nil);
}

address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
	Info(P) = X;
	Next(P) = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
	free (P);
	 }
}

address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Info(P) == X)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	
	 return (P);
}

void InsVFirst (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsVLast (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            address last = First(*L);
            while (Next(last) != Nil) {
                last = Next(last);
            }
            Next(last) = P;
        }
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != Nil && P != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
    }
}

void DelVFirst (List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);
        First(*L) = Next(P);
        DeAlokasi(P);
    }
}

void DelVLast (List *L, infotype *X) {
    if (!ListEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        while (Next(P) != Nil) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }
        DeAlokasi(P);
    }
}

void DelP(List *L, infotype X) {
    if (!ListEmpty(*L)) {
        address P = First(*L), Prec = Nil;
        while (P != Nil && Info(P) != X) {
            Prec = P;
            P = Next(P);
        }
        if (P != Nil) { 
            if (Prec == Nil) { 
                First(*L) = Next(P);
            } else {
                Next(Prec) = Next(P);
            }
            DeAlokasi(P);
        }
    }
}

void PrintInfo(List L) {
    if (ListEmpty(L)) {
        printf("g ada apa apa disini\n");
    } else {
        address P = First(L);
        while (P != Nil) {
            printf("%d -> ", Info(P));
            P = Next(P);
        }
        printf("Nil\n");
    }
}

void DelAll(List *L) {
    infotype X;
    while (!ListEmpty(*L)) {
        DelVFirst(L, &X);
    }
}
