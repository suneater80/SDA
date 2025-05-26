#include <stdio.h>
#include "header6.h"
#include "body6.c"


int main(){
    isi_Tree P;
    infotype X;
    Queue Q;
    Q.front = -1 ; Q.rear = -1;
    create_tree(&P, jml_maks);
    pengisian_tree(&P);

    int pilihan;
    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                // 
                preOrder(P);
                break;

            case 2:
                // 
                inOrder(P); 
                break;

            case 3:
                //
                postOrder(P); 
                break;

            case 4:
                //
                levelOrder(P);
                break;

            case 5:
                // 
                printTree(P);
                break;

            case 6:
                // 
                search(P, X);
                break;

            case 7:
                //
                int jumlah_daun = nbDaun(P);
                printf("Jumlah daun dalam tree: %d\n", jumlah_daun);
                break;

            case 8:
                //
                int nodeLevel;
                int level = getLevelOfNodeByInfo(P, nodeLevel);
                if (level != -1) { 
                        printf("Node tersebut berada pada level: %d \n", level);
                    }
                break;

            case 9:
                //
                int kedalaman = depth(P);
                if (kedalaman >= 0) { 
                        printf("Kedalaman tree adalah: %d (berdasarkan root level 0)\n", kedalaman);
                    }
                break;
                
            case 10:
                //
                isi_Tree P2;
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
    } while (pilihan != 12);

    return 0;
}