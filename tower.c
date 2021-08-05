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
 * Inisialisasi tower, bertujuan untuk mengeset agar isi dari tower kosong
 * @author M Aziz Taufiqurrahman
 */
void createTower(Tower *tower){
	(*tower).top = NULL;
}
/**
 * Mengecek apakah tower memiliki disk atau tidak
 * @author Diana Fauziah
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
 * Memasukkan disk pada tower, dengan panjang disk yang diminta oleh width
 * @author Diana Fauziah
 */
void push(Tower *tower, int width)
{
	Address p;
	
	p = allocate(width);
	if (isEmpty(*tower)){	//tower kosong
		tower->top = p;
	}else{					//tower ada isi
		p->next = tower->top;
		tower->top = p;
	}
	
}
/**
 * Menghapus disk pada tower, dengan panjang disk yang ditampung oleh width
 * @author M Aziz Taufiqurrahman
 */
void pop(Tower *tower, int* width)
{
	if ((*tower).top != NULL) {
		Disk *del = (*tower).top;
		
		if (!del->next) {
		(*tower).top = NULL;
		}
		else {
			(*tower).top = (*tower).top -> next;
		}
		*width = del->width;
		deallocate(del);
		} 
		else {
			printf ("Disk udah kosong");
		}
}
/**
 * Mendapatkan jumlah disk yang berada pada satu tower
 * @author Ihsan Fauzan Hanif
 */
int getDiskCount(Tower* tower)
{
	// jumlah = index top dari tower + 1
	return tower->top + 1;
}
/**
 * Memindahkan blok pada tower yang satu ke tower yang lain
 * @author
 * Diana Fauziah
 * 07/22/21
 */
void moveDisk(Tower* src, Tower* dest)
{
	// lepas disk dari tower satu, ambil datanya, kemudian tower tujuan diisi disk
	// dengan data (width) yang dilepas tadi
    int width = 0;
    pop(src, &width);
    push(dest, width);
}
