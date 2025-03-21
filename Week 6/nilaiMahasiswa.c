#include "nilaiMahasiswa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//membuat list kosong
void createList(List *L) {
    First(*L) = Nil;
}

//check apakah list kosong
boolean isEmpty(List L) {
    return (First(L) == Nil);
}

//alokasi memori untuk node baru
address alokasi(data N) {
    address P = (address)malloc(sizeof(Node));
    if (P != Nil) {
        info(P) = N;  //mengisi data
        next(P) = Nil;  //pointer next diset ke Nil
    }
    return P;
}

//membebaskan memori yang dialok tadi
void dealokasi(address P) {
    free(P);
}

//menampilkan isi list
void printList(List L) {
    address P = First(L);
    if (isEmpty(L)) {
        printf("List kosong.\n");
    } else {
        while (P != Nil) {
            printf("Nama: %s, Nilai UTS: %d\n", info(P).nama, info(P).nilai);
            P = next(P);
        }
    }
}

//mencari elemen list berdasarkan nama
address search(List L, char *nama) {
    address P = First(L);
    while (P != Nil) {
        if (strcmp(info(P).nama, nama) == 0) {
            return P;  //mengembalikan address jika ditemukan
        }
        P = next(P);
    }
    return Nil;  //mengembalikan Nil jika tidak ditemukan
}

//menyalin elemen dari L1 ke L2 yang nilainya > 70
void copyList(List L1, List *L2, int batas) {
    address P = First(L1);
    while (P != Nil) {
        if (info(P).nilai > batas) {
            //membuat node baru di L2 dengan data yang sama
            insertLast(L2, info(P));
        }
        P = next(P);
    }
}

//menghapus duplikat berdasarkan nama
void removeDuplicate(List *L) {
    address P = First(*L);
    while (P != Nil && next(P) != Nil) {
        if (strcmp(info(P).nama, info(next(P)).nama) == 0) {
            //jika nama sama, hapus node berikutnya
            address del = next(P);
            next(P) = next(del);
            dealokasi(del);
        } else {
            P = next(P);
        }
    }
}

//mengurutkan data ascending berdasarkan nama
void sortByAscendNama(List *L) {
    if (isEmpty(*L) || next(First(*L)) == Nil) {
        return;  //list kosong atau hanya memiliki 1 elemen
    }

    address sorted = Nil;  //list yang sudah terurut
    address current = First(*L);

    while (current != Nil) {
        address nextNode = next(current);

        if (sorted == Nil || strcmp(info(current).nama, info(sorted).nama) < 0) {
            //sisipkan di awal
            next(current) = sorted;
            sorted = current;
        } else {
            //cari posisi yang tepat untuk menyisipkan
            address temp = sorted;
            while (next(temp) != Nil && strcmp(info(next(temp)).nama, info(current).nama) < 0) {
                temp = next(temp);
            }
            next(current) = next(temp);
            next(temp) = current;
        }

        current = nextNode;
    }

    First(*L) = sorted;  //update list dengan list yang sudah terurut
}

//mengurutkan data descending berdasarkan nilai
void sortByDescendNilai(List *L) {
    if (isEmpty(*L) || next(First(*L)) == Nil) {
        return;  //list kosong atau hanya memiliki 1 elemen
    }

    address current = First(*L);
    while (current != Nil) {
        address max = current;
        address temp = next(current);

        //cari node dengan nilai terbesar
        while (temp != Nil) {
            if (info(temp).nilai > info(max).nilai) {
                max = temp;
            }
            temp = next(temp);
        }

        //tukar data antara current dan max
        if (max != current) {
            data tempData = info(current);
            info(current) = info(max);
            info(max) = tempData;
        }

        current = next(current);
    }
}

//fungsi untuk menambahkan elemen di awal
void insertFirst(List *L, data N) {
    address P = alokasi(N);
    if (P != Nil) {
        next(P) = First(*L);
        First(*L) = P;
    }
}

//fungsi untuk menambahkan elemen di akhir
void insertLast(List *L, data N) {
    address P = alokasi(N);
    if (P != Nil) {
        if (isEmpty(*L)) {
            First(*L) = P;
        } else {
            address last = First(*L);
            while (next(last) != Nil) {
                last = next(last);
            }
            next(last) = P;
        }
    }
}

//fungsi untuk menambahkan elemen di tengah, sesuai urutan nama
void insertSorted(List *L, data N) {
    address P = alokasi(N);
    if (P != Nil) {
        if (isEmpty(*L) || strcmp(N.nama, info(First(*L)).nama) < 0) {
            //menyisipkan di awal jika list kosong atau nama lebih kecil dari elemen pertama
            next(P) = First(*L);
            First(*L) = P;
        } else {
            address Prec = First(*L);
            while (next(Prec) != Nil && strcmp(info(next(Prec)).nama, N.nama) < 0) {
                Prec = next(Prec);
            }
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

// Fungsi untuk menghapus seluruh elemen
void delAll(List *L) {
    address P;
    while (First(*L) != Nil) {
        P = First(*L);
        First(*L) = next(P);
        dealokasi(P);
    }
}