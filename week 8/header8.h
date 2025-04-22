#ifndef Header8_H
#define Header8_H
#include <stdio.h>

#define MAX_KOTA 10

typedef struct orang *address;
typedef struct orang {
    char nm[20];
    address  next;
} orang;

typedef struct city {
    char kt[20];
    address p;
} kota;



// === Fungsi-Fungsi ADT ===

//inisialisasi array kota
void initKota(kota A[], int* n);

//tambah kota ke array
void tambahKota(kota A[], int* n, char* namaKota);

//tambah nama orang ke kota
void tambahOrang(kota A[], int idx, char* namaOrang);

//hapus data kota dan orang orangnya
void hapusKota(kota A[], int* n, int idx);

//hapus orang tertentu dari kota
void hapusOrang(kota A[], int idx, char* namaOrang);

//tampilkan semua orang di satu kota
void tampilkanKota(kota A[], int idx);

//tampilkan semua data
void tampilkanSemua(kota A[], int n);

// Cari nama orang di semua kota
void cariOrang(kota A[], int n, char* targetNama);

// Menu UI
void tampilkanMenu();

#endif