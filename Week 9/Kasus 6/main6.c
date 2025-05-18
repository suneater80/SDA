#include <stdio.h>
#include "header6.h"


int main(){
    isi_Tree P;

    int pilihan;
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // 
                break;

            case 2:
                // 
                break;

            case 3:
                // 
                break;

            case 4:
                // 
                break;

            case 5:
                // 
                break;

            case 6:
                // 
                break;

            case 7:
                //
                break;

            case 8:
                //
                break;

            case 9:
                // keluar
                break;
                
            case 10:
                //
                break;
                
            case 11:
                //
                break;

            case 12:
                // keluar
                printf("terima kasih telah mencoba\n");
                break;

            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    } while (pilihan != 11);

    return 0;
}