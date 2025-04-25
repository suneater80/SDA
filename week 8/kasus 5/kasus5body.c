#include <malloc.h>
#include <string.h>
#include "kasus5header.h"
#define Kasus5body_c

// inisialisasi untuk kota
void initKota(addressKota* first) {
    *first = NULL;
}

// Tambah nama kota
void tambahKota(addressKota* first, char* namaKota) {
    addressKota baru = (addressKota) malloc(sizeof(kota));
    if (baru != NULL) {
        strcpy(baru->kt, namaKota);
        baru->p = NULL;
        baru->w = NULL;

        if (*first == NULL) {
            *first = baru;
        } else {
            addressKota last = *first;
            while (last->w != NULL) {
                last = last->w;
            }
            last->w = baru;
        }
        printf("Kota '%s' berhasil ditambahkan.\n", namaKota);
    } else {
        printf("Gagal alokasi memori kota.\n");
    }
}

// cari kota berdasarkan nama
addressKota cariKota(addressKota first, char* namaKota) {
    while (first != NULL) {
        if (strcmp(first->kt, namaKota) == 0) {
            return first;
        }
        first = first->w;
    }
    return NULL;
}

// tambah nama orang ke kota tertentu
void tambahOrang(addressKota first, char* namaKota, char* namaOrang) {
    addressKota K = cariKota(first, namaKota);
    if (K == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    addressOrang baru = (addressOrang) malloc(sizeof(orang));
    if (baru != NULL) {
        strcpy(baru->nm, namaOrang);
        baru->next = NULL;

        if (K->p == NULL) {
            K->p = baru;
        } else {
            addressOrang last = K->p;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = baru;
        }
        printf("'%s' berhasil ditambahkan ke kota '%s'.\n", namaOrang, namaKota);
    } else {
        printf("Gagal alokasi memori orang.\n");
    }
}

// hapus seluruh nama orang di kota
void hapusSemuaOrang(addressOrang* head) {
    addressOrang P = *head;
    while (P != NULL) {
        addressOrang temp = P;
        P = P->next;
        free(temp);
    }
    *head = NULL;
}

// hapus kota dan semua orang di dalamnya
void hapusKota(addressKota* first, char* namaKota) {
    addressKota P = *first, prev = NULL;

    while (P != NULL && strcmp(P->kt, namaKota) != 0) {
        prev = P;
        P = P->w;
    }

    if (P == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    // hapus semua orang di kota yang dipilih
    hapusSemuaOrang(&(P->p));

    // Hapus node kota
    if (prev == NULL) {
        *first = P->w;
    } else {
        prev->w = P->w;
    }

    free(P);
    printf("Kota '%s' dan semua orangnya telah dihapus.\n", namaKota);
}

// hapus orang dari kota yang dipilih
void hapusOrang(addressKota first, char* namaKota, char* namaOrang) {
    addressKota K = cariKota(first, namaKota);
    if (K == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    addressOrang P = K->p, prev = NULL;
    while (P != NULL && strcmp(P->nm, namaOrang) != 0) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) {
        printf("Orang '%s' tidak ditemukan di kota '%s'.\n", namaOrang, namaKota);
        return;
    }

    if (prev == NULL) {
        K->p = P->next;
    } else {
        prev->next = P->next;
    }

    free(P);
    printf("'%s' berhasil dihapus dari kota '%s'.\n", namaOrang, namaKota);
}

// tampilkan nama kota beserta semua orang dalam kota tersebut
void tampilkanKota(addressKota first, char* namaKota) {
    addressKota K = cariKota(first, namaKota);
    if (K == NULL) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }

    printf("\nKota: %s\n", K->kt);
    addressOrang P = K->p;
    if (P == NULL) {
        printf("  [tidak ada nama orang]\n");
    } else {
        while (P != NULL) {
            printf("  - %s\n", P->nm);
            P = P->next;
        }
    }
}

// Tampilkan semua kota dan semua orang yang ada
void tampilkanSemua(addressKota first) {
    if (first == NULL) {
        printf("Belum ada data kota.\n");
        return;
    }

    while (first != NULL) {
        printf("\nKota: %s\n", first->kt);
        addressOrang P = first->p;
        if (P == NULL) {
            printf("  [tidak ada nama orang]\n");
        } else {
            while (P != NULL) {
                printf("  - %s\n", P->nm);
                P = P->next;
            }
        }
        first = first->w;
    }
}

// cari nama orang di semua kota
void cariOrang(addressKota first, char* namaOrang) {
    int ditemukan = 0;
    while (first != NULL) {
        addressOrang P = first->p;
        while (P != NULL) {
            if (strcmp(P->nm, namaOrang) == 0) {
                printf("'%s' ditemukan di kota '%s'\n", namaOrang, first->kt);
                ditemukan = 1;
            }
            P = P->next;
        }
        first = first->w;
    }
    if (!ditemukan) {
        printf("Nama '%s' tidak ditemukan di kota manapun.\n", namaOrang);
    }
}

// menu UI
void tampilkanMenu() {
    printf("\n=== MENU KOTA-ORANG ===\n");
    printf("1. Tambah Kota\n");
    printf("2. Tambah Orang ke Kota\n");
    printf("3. Hapus Kota (dan semua orang di dalamnya)\n");
    printf("4. Hapus Orang dari Kota\n");
    printf("5. Tampilkan Orang di Kota Tertentu\n");
    printf("6. Tampilkan Semua Kota dan Orang\n");
    printf("7. Cari Nama Orang\n");
    printf("8. Keluar\n");
    printf("Pilih menu (1-8): ");
}
