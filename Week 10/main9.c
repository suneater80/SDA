#include "header9.h"
#include "body9.c"
#include <stdio.h> 

int main(){

    address root = nil;

    createRoot(&root);
    pengisian_tree(root);
    
    int pilihan;
    char buffer[256]; 
    do
    {
        tampilkanMenu();
        
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Harap masukkan angka.\n");
            while(getchar() != '\n'); 
            continue;
        }
        while(getchar() != '\n');

        switch (pilihan)
        {
        case 1:
            printf("\n--- Struktur Tree (In Order) ---\n");
            inOrder(root);
            printf("\n\n--- Struktur Tree (Level Order) ---\n");
            levelOrder(root);
            break;
        case 2:
        { 
            printf("\nMasukkan teks yang ingin dikonversi ke Morse: ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0; // Menghapus newline dari fgets

            char* morse = stringToMorse(root, buffer);
            printf("Hasil Morse: %s\n", morse);
            free(morse); // Bebaskan memori
            break;
        } 
        case 3:
        { 
            printf("\nMasukkan kode Morse (pisahkan huruf dengan spasi, kata dengan '/'): ");
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0; // Menghapus newline
            
            char* text = morseToString(root, buffer);
            printf("Hasil Teks: %s\n", text);
            free(text); 
            break;
        } 
        case 4:
            printf("Terimakasih telah menggunakan program kami\n");
            break;
        default:
            printf("Input tidak valid, coba lagi\n");
            break;
        }
    } while (pilihan != 4);
    
    freeTree(root);
    root = nil;
    
    return 0;
}