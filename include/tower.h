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

#ifndef __TOWER_HEADER_
#define __TOWER_HEADER_

#include <stdbool.h>
#include "all.h"

// Pointer pada cakram
typedef struct _Disk* Address;

// Cakram pada menara
typedef struct _Disk {
    int width;
    Address next;
} Disk;

// Menara
typedef struct _Tower {
    Address top;
} Tower;

/**
 * [Deskripsi]
 * Inisialisasi tower, bertujuan untuk mengeset agar isi dari tower kosong
 * 
 * @author
 */
void createTower(Tower *tower);

/**
 * [Deskripsi]
 * Inisialisasi disk, bertujuan untuk mengatur agar disk memiliki isi (panjang) sesuai
 * dengan width
 * 
 * @author
 */
void createDisk(int width);

/**
 * [Deskripsi]
 * Membuat disk baru dengan panjang disk yang telah ditentukan
 * 
 * @author
 */
Address allocate(Address disk, int width);

/**
 * [Deskripsi]
 * Membebaskan memori yang dipesan oleh pointer pada disk
 * 
 * @author
 */
void deallocate(Address disk);

/**
 * [Deskripsi]
 * Mengecek apakah tower memiliki disk atau tidak
 * 
 * @author
 */
bool isEmpty(Tower tower);

/**
 * [Deskripsi]
 * Memasukkan disk pada tower, dengan panjang disk yang diminta oleh width
 * 
 * @author
 */
void push(Tower *tower, int width);

/**
 * [Deskripsi]
 * Menghapus disk pada tower, dengan panjang disk yang ditampung oleh width
 * 
 * @author
 */
void pop(Tower *tower, int* width);

#endif
