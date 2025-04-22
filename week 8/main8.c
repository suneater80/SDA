#include "header8.h"
#include "body8.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    kota A[MAX_KOTA];
    int jumlahKota;
    int pilihan, idx;
    char nama[20];

    initKota(A, &jumlahKota);

    do {
        tampilkanMenu();
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Program akan berhenti.\n");
            break;
        }
        getchar();
        

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                tambahKota(A, &jumlahKota, nama);
                break;

            case 2:
                printf("Pilih kota (0 sampai %d): ", jumlahKota - 1);
                scanf("%d", &idx);
                getchar();
                if (idx >= 0 && idx < jumlahKota) {
                    printf("Masukkan nama orang: ");
                    fgets(nama, sizeof(nama), stdin);
                    nama[strcspn(nama, "\n")] = 0;
                    tambahOrang(A, idx, nama);
                } else {
                    printf("Indeks kota tidak valid.\n");
                }
                break;

            case 3:
                printf("Pilih kota yang akan dihapus (0 sampai %d): ", jumlahKota - 1);
                scanf("%d", &idx);
                getchar();
                if (idx >= 0 && idx < jumlahKota) {
                    hapusKota(A, &jumlahKota, idx);
                } else {
                    printf("Indeks tidak valid.\n");
                }
                break;

            case 4:
                printf("Pilih kota (0 sampai %d): ", jumlahKota - 1);
                scanf("%d", &idx);
                getchar();
                if (idx >= 0 && idx < jumlahKota) {
                    printf("Masukkan nama orang yang ingin dihapus: ");
                    fgets(nama, sizeof(nama), stdin);
                    nama[strcspn(nama, "\n")] = 0;
                    hapusOrang(A, idx, nama);
                } else {
                    printf("Indeks kota tidak valid.\n");
                }
                break;

            case 5:
                printf("Pilih kota (0 sampai %d): ", jumlahKota - 1);
                scanf("%d", &idx);
                getchar();
                if (idx >= 0 && idx < jumlahKota) {
                    tampilkanKota(A, idx);
                } else {
                    printf("Indeks kota tidak valid.\n");
                }
                break;

            case 6:
                tampilkanSemua(A, jumlahKota);
                break;

            case 7:
                printf("Masukkan nama orang yang ingin dicari: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                cariOrang(A, jumlahKota, nama);
                break;

            case 8:
                printf("Have a nice day\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 8);

    return 0;
}