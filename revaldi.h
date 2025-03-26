#ifndef REVALDI_H
#define REVALDI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int infotype;  // Jika infotype hanya berupa integer

// Struktur Node Linked List
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

// Definisi List sebagai address
typedef address List;

// Fungsi dasar linked list
void CreateList (List * L);
void PrintInfo (List L);
// Membuat node baru
void Create_Node(address *p, infotype data);
// Menghapus node
void DeAlokasi(address *p);
// Mengecek apakah list kosong
bool isEmpty(List L);
// Menyisipkan data secara terurut berdasarkan nama
void InsertSortedByNama(List *L, infotype data);
// Mencetak seluruh elemen dalam list
void PrintList(List L);

// *** Operasi Pencarian ***
address Search(List L, infotype X);
bool FSearch(List L, address P);
address SearchPrec(List L, infotype X);

// Opera untuk menghapus
void DelVFirst(List *L, infotype *X);
void DelVLast(List *L, infotype *X);
void DelFirst(List *L, address *P);
void DelP(List *L, infotype X);
void DelLast(List *L, address *P);
void DelAfter(List *L, address *Pdel, address Prec);

// Operasi menyisipkan node
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);
void InsertFirst(List *L, address P);
void InsertAfter(List *L, address P, address Prec);
void InsertLast(List *L, address P);

#endif
