#include "menu.h"
#include <stdio.h>

void tampilkanMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Tambah Data Mahasiswa\n");
    printf("2. Tampilkan List L1 (Ascending by Nama)\n");
    printf("3. Tampilkan List L1 (Descending by Nilai)\n");
    printf("4. Salin Data ke L2 (Nilai > 70)\n");
    printf("5. Tampilkan List L2\n");
    printf("6. Hapus Duplikat di L2\n");
    printf("7. Hapus List L1 dan L2\n");
    printf("8. Cari Data Mahasiswa\n");  // Opsi baru untuk search
    printf("9. Keluar\n");
    printf("Pilih menu: ");
}

void prosesMenu(List *L1, List *L2) {
    int pilihan;
    data nana;
    char namaCari[30];  // Variabel untuk menyimpan nama yang dicari

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // Tambah Data Mahasiswa
                printf("Masukkan nama: ");
                scanf("%s", nana.nama);
                printf("Masukkan nilai: ");
                scanf("%d", &nana.nilai);
                insertSorted(L1, nana);
                printf("Data berhasil ditambahkan!\n");
                break;

            case 2:
                // Tampilkan List L1 (Ascending by Nama)
                printf("Isi List L1 (Ascending by Nama):\n");
                printList(*L1);
                break;

            case 3:
                // Tampilkan List L1 (Descending by Nilai)
                sortByDescendNilai(L1);
                printf("Isi List L1 (Descending by Nilai):\n");
                printList(*L1);
                break;

            case 4:
                // Salin Data ke L2 (Nilai > 70)
                copyList(*L1, L2, 70);
                printf("Data dengan nilai > 70 telah disalin ke L2.\n");
                break;

            case 5:
                // Tampilkan List L2
                printf("Isi List L2:\n");
                printList(*L2);
                break;

            case 6:
                // Hapus Duplikat di L2
                removeDuplicate(L2);
                printf("Duplikat di L2 telah dihapus.\n");
                break;

            case 7:
                // Hapus List L1 dan L2
                delAll(L1);
                delAll(L2);
                printf("List L1 dan L2 telah dihapus.\n");
                break;

            case 8:
                // Cari Data Mahasiswa
                printf("Masukkan nama yang ingin dicari: ");
                scanf("%s", namaCari);
                address hasilSearch = search(*L1, namaCari);
                if (hasilSearch != Nil) {
                    printf("Data ditemukan:\n");
                    printf("Nama: %s, Nilai UTS: %d\n", info(hasilSearch).nama, info(hasilSearch).nilai);
                } else {
                    printf("Data tidak ditemukan.\n");
                }
                break;

            case 9:
                // Keluar
                printf("Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 9);
}