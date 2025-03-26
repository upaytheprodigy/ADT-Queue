#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "queue.c"

int main() {
    Queue Q;
    CreateQueue(&Q);
    int pilihan, nomor = 0, diproses;
    
    do {
        printf("\n=== SELAMAT DATANG DI BANK ===\n");
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Panggil Nomor Antrian\n");
        printf("3. Lihat Daftar Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                nomor++;
                EnQueue(&Q, nomor);
                printf("Nomor antrian Anda adalah %d. Silakan menunggu giliran.\n", nomor);
                printQueue(Q);
                break;

            case 2:
                if (!is_Empty(Q)) {
                    deQueue(&Q, &diproses);
                    printf("Nomor antrian %d dipanggil ke loket. Silakan menuju teller.\n", diproses);
                    printQueue(Q);
                } else {
                    printf("Tidak ada pelanggan dalam antrian.\n");
                }
                break;

            case 3:
                printQueue(Q);
                break;

            case 4:
                printf("Terima kasih telah menggunakan layanan kami. Selamat datang kembali!\n");
                break;

            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

    } while (pilihan != 4);

    return 0;
}