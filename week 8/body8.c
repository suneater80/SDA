#include <malloc.h>
#include <string.h>
#include "header8.h"
#define Body8_C


//inisialisasi array kota
void initKota(kota A[], int* n) {
    *n = 0;
}

//tambah kota baru ke array A
void tambahKota(kota A[], int* n, char* namaKota) {
    if (*n >= MAX_KOTA) {
        printf("Maksimum jumlah kota tercapai!\n");
        return;
    }

    strcpy(A[*n].kt, namaKota);
    A[*n].p = NULL;
    (*n)++;
    printf("Kota '%s' berhasil ditambahkan.\n", namaKota);
}

//tambah nama orang ke linked list kota
void tambahOrang(kota A[], int idx, char* namaOrang) {
    address baru = (address) malloc(sizeof(orang));
    if (baru == NULL) {
        printf("Gagal alokasi memori untuk orang.\n");
        return;
    }

    strcpy(baru->nm, namaOrang);
    baru->next = NULL;

    if (A[idx].p == NULL) {
        A[idx].p = baru;
    } else {
        address last = A[idx].p;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = baru;
    }
    printf("'%s' berhasil ditambahkan ke kota '%s'.\n", namaOrang, A[idx].kt);
}

//hapus semua orang dari kota dan geser array
void hapusKota(kota A[], int* n, int idx) {
    address P = A[idx].p;
    while (P != NULL) {
        address temp = P;
        P = P->next;
        free(temp);
    }

    //geser elemen kota di array
    for (int i = idx; i < *n - 1; i++) {
        A[i] = A[i + 1];
    }
    (*n)--;

    printf("Kota dan seluruh data orangnya telah dihapus.\n");
}

//hapus orang dari linked list kota
void hapusOrang(kota A[], int idx, char* namaOrang) {
    address P = A[idx].p, prev = NULL;

    while (P != NULL && strcmp(P->nm, namaOrang) != 0) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        printf("Orang dengan nama '%s' tidak ditemukan di kota '%s'.\n", namaOrang, A[idx].kt);
        return;
    }

    if (prev == NULL) {
        A[idx].p = P->next;
    } else {
        prev->next = P->next;
    }

    free(P);
    printf("'%s' berhasil dihapus dari kota '%s'.\n", namaOrang, A[idx].kt);
}

// Tampilkan semua orang di kota tertentu
void tampilkanKota(kota A[], int idx) {
    printf("\nKota: %s\n", A[idx].kt);
    address P = A[idx].p;

    if (P == NULL) {
        printf("  [tidak ada nama orang]\n");
        return;
    }

    while (P != NULL) {
        printf("  - %s\n", P->nm);
        P = P->next;
    }
}

// Tampilkan semua kota dan orang-orangnya
void tampilkanSemua(kota A[], int n) {
    if (n == 0) {
        printf("\nBelum ada data kota.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        tampilkanKota(A, i);
    }
}

// Cari nama orang di semua kota
void cariOrang(kota A[], int n, char* targetNama) {
    int ditemukan = 0;

    for (int i = 0; i < n; i++) {
        address P = A[i].p;
        while (P != NULL) {
            if (strcmp(P->nm, targetNama) == 0) {
                printf("'%s' ditemukan di kota '%s'\n", targetNama, A[i].kt);
                ditemukan = 1;
            }
            P = P->next;
        }
    }

    if (!ditemukan) {
        printf("Nama '%s' tidak ditemukan di kota manapun.\n", targetNama);
    }
}

// Menu tampilan
void tampilkanMenu() {
    printf("\n=== MENU UTAMA ===\n");
    printf("1. Tambah Kota Baru\n");
    printf("2. Tambah Nama Orang ke Kota\n");
    printf("3. Hapus Kota (dan semua nama orang di dalamnya)\n");
    printf("4. Hapus Nama Orang dari Kota\n");
    printf("5. Tampilkan Seluruh Nama Orang di Kota Tertentu\n");
    printf("6. Tampilkan Seluruh Kota dan Nama Orangnya\n");
    printf("7. Cari Nama Orang di Semua Kota\n");
    printf("8. Keluar Program\n");
    printf("Pilih menu (1-8): ");
}
