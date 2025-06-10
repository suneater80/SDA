#ifndef Body9_H
#define Body9_H
#include "header9.h"


void createRoot(address *root) {
    *root = createNode('~'); // '~' sebagai karakter awal, agar tidak dikira nil
}

address createNode(char info) {
    address newNode = (address)malloc(sizeof(btree));
    newNode->info = info;
    newNode->L_ptr = nil;
    newNode->R_ptr = nil;
    return newNode;
}

void insertMorse(address root, const char *path, char value) {
    address current = root;
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '.') { // '.' ke kiri (L_ptr)
            if (current->L_ptr == nil) {
                current->L_ptr = createNode('~'); // node perantara jika belum ada node
            }
            current = current->L_ptr;
        } else if (path[i] == '-') { // '-' ke kanan (R_ptr)
            if (current->R_ptr == nil) {
                current->R_ptr = createNode('~'); // node perantara jika belum ada node
            }
            current = current->R_ptr;
        }
    }
    current->info = value; // Set info di node tujuan
}


void pengisian_tree(address root) {
    
    insertMorse(root, ".", 'A');
    insertMorse(root, "..", 'C');
    insertMorse(root, "...", 'G');
    insertMorse(root, "....", 'O');
    insertMorse(root, ".....", '1');
    insertMorse(root, "....-", '3');
    insertMorse(root, "...-", 'P');
    insertMorse(root, "...--", '5'); 
    insertMorse(root, "..-", 'H');
    insertMorse(root, "..-.", 'Q');
    insertMorse(root, "..--", '~');
    insertMorse(root, "..---", '7');
    insertMorse(root, ".-", 'D');
    insertMorse(root, ".-.", 'I'); 
    insertMorse(root, ".-..", 'R'); 
    insertMorse(root, ".-.-", '~'); 
    insertMorse(root, ".-.-.", '9');
    insertMorse(root, ".--", 'J'); 
    insertMorse(root, ".--.", 'S'); 
    insertMorse(root, ".---", 'T'); 
    insertMorse(root, ".----", ' ');
    
    // P->R_ptr...
    insertMorse(root, "-", 'B');
    insertMorse(root, "-.", 'E');
    insertMorse(root, "-..", 'K');
    insertMorse(root, "-...", 'U');
    insertMorse(root, "-....", '8');
    insertMorse(root, "-..-", 'V'); 
    insertMorse(root, "-.-", 'L');
    insertMorse(root, "-.-.", 'W');
    insertMorse(root, "-.--", 'X');
    insertMorse(root, "--", 'F');
    insertMorse(root, "--.", 'M');
    insertMorse(root, "--..", 'Y');
    insertMorse(root, "--...", '6');
    insertMorse(root, "--.-", 'Z');
    insertMorse(root, "---", 'N');
    insertMorse(root, "---.", '0'); 
    insertMorse(root, "---..", '4');
    insertMorse(root, "----", '~');
    insertMorse(root, "----.", '2');
}

void freeTree(address node) {
    if (node == nil) return;
    freeTree(node->L_ptr);
    freeTree(node->R_ptr);
    free(node);
}


void tampilkanMenu(){
    printf("\n=== MENU ===\n");
    printf("1. Traversal InOrder\n");
    printf("2. Konversi String -> Morse\n");
    printf("3. Konversi Morse -> String\n");
    printf("4.Exit\n");
    printf("Pilih menu: ");
}

void inOrder(address P) {
    if (P == nil) {
        return;
    }
    inOrder(P->L_ptr);
    if (P->info != '~') {
        printf("%c ", P->info);
    }
    inOrder(P->R_ptr);
}


Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, address treeNode) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

address dequeue(Queue* q) {
    if (q->front == NULL) return nil;
    QueueNode* temp = q->front;
    address treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return treeNode;
}

boolean isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

boolean findMorsePath(address node, char target, char* path, int depth) {
    if (node == nil) return false;
    if (node->info == target) {
        path[depth] = '\0';
        return true;
    }
    // Cek subtree kiri
    path[depth] = '.';
    if (findMorsePath(node->L_ptr, target, path, depth + 1)) return true;
    // Cek subtree kanan
    path[depth] = '-';
    if (findMorsePath(node->R_ptr, target, path, depth + 1)) return true;
    
    return false;
}

char* stringToMorse(address root, const char* text) {
    char* morseResult = (char*)malloc(strlen(text) * 6 + 1); // Alokasi memori awal
    morseResult[0] = '\0';
    
    for (int i = 0; text[i] != '\0'; i++) {
        char singleChar = toupper(text[i]);
        if (singleChar == ' ') {
            strcat(morseResult, "/ "); // Spasi antar kata
        } else {
            char path[10]; // Path morse tidak akan lebih dari 9 char
            if (findMorsePath(root, singleChar, path, 0)) {
                strcat(morseResult, path);
                strcat(morseResult, " "); // Spasi antar huruf
            }
        }
    }
    return morseResult;
}

char* morseToString(address root, const char* morseCode) {
    char* textResult = (char*)malloc(strlen(morseCode) + 1);
    textResult[0] = '\0';
    
    // Salin morseCode agar bisa dimodifikasi oleh strtok
    char* morseCopy = strdup(morseCode);
    char* token = strtok(morseCopy, " ");

    while(token != NULL) {
        if (strcmp(token, "/") == 0) {
            strcat(textResult, " "); // Tambah spasi untuk kata baru
        } else {
            address current = root;
            for (int i = 0; token[i] != '\0' && current != nil; i++) {
                if (token[i] == '.') {
                    current = current->L_ptr;
                } else if (token[i] == '-') {
                    current = current->R_ptr;
                }
            }
            if (current != nil && current->info != '~') {
                char singleCharStr[2] = {current->info, '\0'};
                strcat(textResult, singleCharStr);
            }
        }
        token = strtok(NULL, " ");
    }
    
    free(morseCopy);
    return textResult;
}

void levelOrder(address root) {
    if (root == nil) {
        printf("Tree kosong.\n");
        return;
    }
    Queue* q = createQueue();
    enqueue(q, root);
    
    while (!isQueueEmpty(q)) {
        int levelSize = 0;
        QueueNode* temp = q->front;
        while(temp != NULL){
            levelSize++;
            temp = temp->next;
        }

        printf("Level: ");
        for(int i=0; i<levelSize; i++){
            address current = dequeue(q);
             // Cetak info node, ganti '~' dengan '_' agar lebih rapi
            printf("%c ", (current->info == '~' ? '_' : current->info));

            if (current->L_ptr != nil) {
                enqueue(q, current->L_ptr);
            }
            if (current->R_ptr != nil) {
                enqueue(q, current->R_ptr);
            }
        }
        printf("\n");
    }
    free(q);
}

#endif