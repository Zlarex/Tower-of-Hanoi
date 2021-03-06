/**
 * Kelompok 6
 * 
 * Anggota:
 * 201524003 - Diana Fauziah
 * 201524011 - Ihsan Fauzan Hanif
 * 201524014 - Muhammad Aziz Taufiqurrahman
 * 
 * tower.h
 * Struktur data yang merepresentasikan unit Stack yang
 * dikhususkan untuk permainan Tower of Hanoi.
 */

#ifndef __TOWER
#define __TOWER

#include <stdbool.h>
#include "all.h"

// Tower (Stack)
typedef struct _Tower {
    int width[MAX_DISK];
    int top;
} Tower;

/**
 * Inisialisasi tower, bertujuan untuk mengeset agar isi dari tower kosong
 * @author M Aziz Taufiqurrahman
 */
void createTower(Tower *tower);
/**
 * Mengecek apakah tower memiliki disk atau tidak
 * @author Diana Fauziah
 */
bool isEmpty(Tower tower);
/**
 * Memasukkan disk pada tower, dengan panjang disk yang diminta oleh width
 * @author Diana Fauziah
 */
void push(Tower *tower, int width);
/**
 * Menghapus disk pada tower, dengan panjang disk yang ditampung oleh width
 * @author M Aziz Taufiqurrahman
 */
void pop(Tower *tower, int* width);
/**
 * Mendapatkan jumlah disk yang berada pada satu tower
 * @author Ihsan Fauzan Hanif
 */
int getDiskCount(Tower* tower);
/**
 * Memindahkan blok pada tower yang satu ke tower yang lain
 * @author Diana Fauziah
 */
void moveDisk(Tower* src, Tower* dest);

#endif
