#ifndef KASUS5HEADER_H
#define KASUS5HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tipe data untuk pointer
typedef struct orang* addressOrang;
typedef struct kota* addressKota;

// struct orang
typedef struct orang {
    char nm[20];            
    addressOrang next;      
} orang;

// struct kota
typedef struct kota {
    char kt[20];            
    addressOrang p;         
    addressKota w;          
} kota;

// modul ADT

// Inisiasi linklist kota
void initKota(addressKota* first);

// tambah nama kota baru di akhir list
void tambahKota(addressKota* first, char* namaKota);

// tambah nama orang ke kota yang dipilih
void tambahOrang(addressKota first, char* namaKota, char* namaOrang);

// hapus kota beserta seluruh nama orang di dalamnya
void hapusKota(addressKota* first, char* namaKota);

// hapus orang dari kota yang dipilih
void hapusOrang(addressKota first, char* namaKota, char* namaOrang);

// tampilkan semua kota dan orang yang ada
void tampilkanSemua(addressKota first);

// tampilkan nama orang di satu kota yang dipilih
void tampilkanKota(addressKota first, char* namaKota);

// cari orang di seluruh kota
void cariOrang(addressKota first, char* namaOrang);

// menu UI
void tampilkanMenu();

#endif
