#include "antriBank.h"

// Inisialisasi queue
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
    q->nextNumber = 1;
}

// Menambahkan pelanggan ke antrian
void enqueue(Queue *q) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->nomorAntrian = q->nextNumber;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Nomor antrian %d telah ditambahkan.\n", q->nextNumber);
    q->nextNumber++;
    printQueue(q);
}

// Memproses pelanggan (yang paling depan)
void dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    printf("Nomor antrian %d sedang diproses.\n", temp->nomorAntrian);
    free(temp);
    printQueue(q);
}

// Mencetak antrian saat ini
void printQueue(Queue *q) {
    if (q->front == NULL) {
        printf("Antrian: []\n");
        return;
    }

    Node *current = q->front;
    printf("Antrian: [");
    while (current != NULL) {
        printf("%d", current->nomorAntrian);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}

// Menu utama
int main() {
    Queue q;
    initQueue(&q);
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 4);

    // Membersihkan memori jika antrian belum kosong
    while (q.front != NULL) {
        dequeue(&q);
    }

    return 0;
}