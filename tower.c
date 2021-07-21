/**
 * Kelompok 6
 * 
 * Anggota:
 * 201524003 - Diana Fauziah
 * 201524011 - Ihsan Fauzan Hanif
 * 201524014 - Muhammad Aziz Taufiqurrahman
 * 
 * tower.c
 * Implementasi kode program dari struktur data pada file tower.h
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "include/all.h"

/**
 * [Deskripsi]
 * Inisialisasi tower, bertujuan untuk mengeset agar isi dari tower kosong
 * 
 * @author
 */
void createTower(Tower *tower)
{

}

/**
 * [Deskripsi]
 * Inisialisasi disk, bertujuan untuk mengatur agar disk memiliki isi (panjang) sesuai
 * dengan width
 * 
 * @author
 */
void createDisk(Address disk, int width)
{
	disk.width = width;
	disk->next = NULL;
}

/**
 * [Deskripsi]
 * Membuat disk baru dengan panjang disk yang telah ditentukan
 * 
 * @author
 */
Address allocate(Address disk, int width)
{

}

/**
 * [Deskripsi]
 * Membebaskan memori yang dipesan oleh pointer pada disk
 * 
 * @author
 */
void deallocate(Address disk)
{

}

/**
 * [Deskripsi]
 * Mengecek apakah tower memiliki disk atau tidak
 * 
 * @author
 */
bool isEmpty(Tower tower)
{
	if(tower.top == NULL){
		return true;
	}else {
		return false;
	}
}


/**
 * [Deskripsi]
 * Memasukkan disk pada tower, dengan panjang disk yang diminta oleh width
 * 
 * @author
 */
void push(Tower *tower, int width)
{
	Address p,q;
	
	p = allocate(tower, width);
	if (isEmpty(*tower)){	//tower kosong
		tower->top = p;
	}else{					//tower ada isi
		p->next = tower->top;
		tower->top = p;
	}
	
}

/**
 * [Deskripsi]
 * Menghapus disk pada tower, dengan panjang disk yang ditampung oleh width
 * 
 * @author
 */
void pop(Tower *tower, int* width)
{

}
