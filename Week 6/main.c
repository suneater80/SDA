#include "nilaiMahasiswa.h"
#include "nilaiMahasiswa.c"
#include "menu.h"
#include "menu.c"

int main() {
    List L1, L2;

    // Inisialisasi list
    createList(&L1);
    createList(&L2);

    // Menjalankan menu
    prosesMenu(&L1, &L2);

    return 0;
}