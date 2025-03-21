#include "Praktikum5.h"
#include "bodyPraktikum5.c"
#include <stdio.h>

int main()
{
    /* Kamus Lokal */
    List MyList;
    infotype isi;
    address P, Prec;

    /* Program */
    CreateList(&MyList);  // list kosong dulu gess

    // soal 1 Masukkan bilangan 7 sebagai elemen pertama {Insert First}
    InsVFirst(&MyList, 7);     // X=7
    printf("Setelah memasukkan 7:\n");
    PrintInfo(MyList);

    // soal 2 Masukkan bilangan 11 sebagai elemen kedua {Insert Last}
    InsVLast(&MyList, 11);    // X=11
    printf("Setelah memasukkan 11:\n");
    PrintInfo(MyList);

    // soal 3 Masukkan bilangan 9 di antara bilangan 7 dan 11 {Insert After}
    P = Alokasi(9);
    Prec = Search(MyList, 7);  // Cari alamat dari bilangan 7,  disini make looping ygy
    if (P != Nil && Prec != Nil) {
        InsertAfter(&MyList, P, Prec);      // nanti bilangan yang mau dimasukin bakal masuk ke next Prec
    }
    printf("Setelah memasukkan 9 di antara 7 dan 11:\n");
    PrintInfo(MyList);

    // soal 4 Masukkan bilangan 5 di awal list {Insert First}
    InsVFirst(&MyList, 5);      //nanti dihubungin ke First, dibikin node baru dulu
    printf("Setelah memasukkan 5 di awal:\n");
    PrintInfo(MyList);

    // soal 5 Masukkan bilangan 13 di akhir list {Insert Last}
    InsVLast(&MyList, 13);      //nanti dihubungin ke Last, dibikin node baru dulu
    printf("Setelah memasukkan 13 di akhir:\n");
    PrintInfo(MyList);

    // soal 6 Hapus elemen terakhir (bilangan 13) pada list {Delete Last}
    DelVLast(&MyList, &isi);    //pertama dia menelusuri elemen terakhir dulu, abis itu hapus. disini make dealok yaw
    printf("Setelah menghapus elemen terakhir (%d):\n", isi);
    PrintInfo(MyList);

    // soal 7 Hapus bilangan 7 pada list {DelP}
    DelP(&MyList, 7);           //modul akan mencari 7 (elemen X), klo udah nemu baru di hapus deh. janlup make dialok
    printf("Setelah menghapus elemen 7:\n");
    PrintInfo(MyList);

    // soal 8 Hapus elemen pertama (bilangan 5) pada list {Delete First}
    DelVFirst(&MyList, &isi);   //o ya nilai yang mau dihapus disimpen dulu, baru diputus. nanti baru dialok
    printf("Setelah menghapus elemen pertama (%d):\n", isi);
    PrintInfo(MyList);

    // soal 9 Hapus semua elemen list {DelAll}
    DelAll(&MyList);    //simpelny hapus 1 per 1, biar mudah jadi make modul DelVFirst aja(di looping ygy). abis tu kosong deh listnya:)
    printf("Setelah menghapus semua elemen list:\n");
    PrintInfo(MyList);

    return 0;
}
