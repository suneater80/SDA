#include "kasus5header.h"
#include "kasus5body.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    addressKota firstKota;
    int pilihan;
    char namaKota[20], namaOrang[20];

    initKota(&firstKota);

    do {
        tampilkanMenu();
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid\n");
            break;
        }
        getchar();

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tambahKota(&firstKota, namaKota);
                break;

            case 2:
                printf("Masukkan nama kota tujuan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                tambahOrang(firstKota, namaKota, namaOrang);
                break;

            case 3:
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                hapusKota(&firstKota, namaKota);
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                printf("Masukkan nama orang yang ingin dihapus: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                hapusOrang(firstKota, namaKota, namaOrang);
                break;

            case 5:
                printf("Masukkan nama kota yang ingin ditampilkan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = 0;
                tampilkanKota(firstKota, namaKota);
                break;

            case 6:
                tampilkanSemua(firstKota);
                break;

            case 7:
                printf("Masukkan nama orang yang ingin dicari: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0;
                cariOrang(firstKota, namaOrang);
                break;

            case 8:
                printf("Have a nice dayy\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan pilih 1 sampai 8.\n");
        }

    } while (pilihan != 8);

    return 0;
}
