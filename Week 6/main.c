#include "nilaiMahasiswa.h"
#include "nilaiMahasiswa.c"
#include "menu.h"
#include "menu.c"

int main() {
    List L1, L2;

    // inisiasi list
    createList(&L1);
    createList(&L2);

    // masuk ke menu ygy
    prosesMenu(&L1, &L2);

    return 0;
}