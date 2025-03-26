#include "revaldi.h"

// Deklarasi fungsi-fungsi yang berada di mahasiswa.h

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
    *L = NULL;
}

// Membuat node baru dengan data tertentu
void Create_Node(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    }
}

// Menghapus node dan membebaskan memori
void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

// Mengecek apakah list kosong
bool isEmpty(List L) {
    return (L == NULL);
}

bool isFull(List L) {
    address temp = (address)malloc(sizeof(ElmtList));
    if (temp == NULL) {
        return true;  // Memori penuh
    } else {
        free(temp);
        return false; // Masih bisa menambah elemen
    }
}

// *** OPERASI PENYISIPAN ***

// Menyisipkan elemen dengan alokasi baru di awal list
void InsVFirst(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        InsertFirst(L, P);
    }
}

// Menyisipkan elemen di awal list berdasarkan alamat
void InsertFirst(List *L, address P) {
    P->next = *L;
    *L = P;
}

// Menyisipkan elemen dengan alokasi baru di akhir list
void InsVLast(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        InsertLast(L, P);
    }
}

// Menyisipkan elemen di akhir list berdasarkan alamat
void InsertLast(List *L, address P) {
    if (isEmpty(*L)) {
        *L = P;
    } else {
        address temp = *L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

// Menyisipkan elemen setelah elemen tertentu
void InsertAfter(List *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// *** OPERASI PENGHAPUSAN ***

// Menghapus elemen pertama
void DelVFirst(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        DelFirst(L, &P);
        *X = P->info;
        DeAlokasi(&P);
    }
}

// Menghapus elemen pertama berdasarkan alamat
void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*L)->next;
        (*P)->next = NULL;
    }
}

// Menghapus elemen terakhir
void DelVLast(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        DelLast(L, &P);
        *X = P->info;
        DeAlokasi(&P);
    }
}

// Menghapus elemen terakhir berdasarkan alamat
void DelLast(List *L, address *P) {
    if (!isEmpty(*L)) {
        address temp = *L, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        *P = temp;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *L = NULL;
        }
    }
}

// Menghapus elemen tertentu dari list
void DelP(List *L, infotype X) {
    address P = *L, prev = NULL;

    while (P != NULL && P->info != X) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {  // Elemen ditemukan
        if (prev == NULL) {  // Elemen pertama yang dihapus
            *L = P->next;
        } else {  // Elemen di tengah atau akhir
            prev->next = P->next;
        }
        DeAlokasi(&P);
    }
}

// Menghapus elemen setelah elemen tertentu
void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        (*Pdel)->next = NULL;
    }
}

void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

 {
    address P = L;
    if (isEmpty(L)) {
        printf("List Kosong\n");
    } else {
        while (P != NULL) {
            printf("%d ", P->info);
            P = P->next;
        }
        printf("\n");
    }
}