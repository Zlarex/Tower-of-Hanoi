/**
 * Kelompok 6
 * 
 * Anggota:
 * 201524003 - Diana Fauziah
 * 201524011 - Ihsan Fauzan Hanif
 * 201524014 - Muhammad Aziz Taufiqurrahman
 * 
 * game.c
 * Implementasi kode program dari struktur data pada file game.h
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "include/all.h"

/**
 * [Deskripsi]
 * Inisialisasi sistem Game, bertujuan untuk mengatur agar semua
 * informasi terkait dengan Game bernilai kosong
 * 
 * @author
 */
void createGame(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu untuk memulai permainan baru
 * 
 * @author
 */
void menuPlayGame(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu untuk memuat permainan lama (yang telah tersimpan)
 * 
 * @author
 */
void menuLoadGame(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu untuk membuat permainan yang dikustomisasi oleh pemain
 * 
 * @author
 */
void menuPracticeGame(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu untuk menampilkan top 10 pemain dengan skor tertinggi
 * 
 * @author
 */
void menuHighScore(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu untuk menampilkan informasi mengenai game dan/atau developer
 * 
 * @author
 * Diana Fauziah
 * 07/21/21
 */
void menuCredits(Game *game)
{
	printf("***********************************************************************************\n");
	printf("/t/t/t/t TOWER OF HANOI\n");
	printf("***********************************************************************************\n\n");
	printf("/t/t Permainan yang bertujuan untuk melatih kemampuan\n");
	printf("/t/t matematis anda dalam memperhitungkan langkah untuk\n");
	printf("/t/t menyelesaikan permasalahan yang dilakukan dengan cara\n");
	printf("/t/t memindahkan seluruh disk pada tower yang ada di ujung\n");
	printf("===================================================================================\n\n");
	printf("--------------------------------------------------------\n");
	printf("|Tower of Hanoi dibuat oleh :					       |\n");
	printf("|Diana Fauziah - Tunjukkan Versi Terbaik Anda!!!!      |\n");
	printf("|Ihsan Fauzan Hanif - Hanyalah seorang remaja (iyakah?)|\n");
	printf("|                     Menyukai dunia pemrograman	   |\n");
	printf("|M Aziz Taufiqurrahman - (deskripsi diri)			   |\n");
	printf("--------------------------------------------------------\n");
}

/**
 * [Deskripsi]
 * Menu untuk keluar dari program
 * 
 * @author
 */
void menuExit(Game *game)
{

}

/**
 * [Deskripsi]
 * Menu sebagai tempat berhenti sesaat sebelum permainan dimulai
 * 
 * @author
 */
void menuLobby(Game *game)
{

}

/**
 * [Deskripsi]
 * Mendapatkan disk maksimal yang bisa dimasukkan berdasarkan level dari tower 
 * 
 * @author
 */
int getMaxDisk(int towerLevel)
{

}

/**
 * [Deskripsi]
 * Mendapatkan waktu maksimal yang bisa digunakan untuk bermain berdasarkan level dari tower
 * 
 * @author
 */
int getMaxTime(int towerLevel)
{

}

/**
 * [Deskripsi]
 * Mendapatkan pergerakan minimal yang bisa dilakukan untuk menyelesaikan permainan
 * 
 * @author
 */
int getMinMoves(int towerLevel)
{

}

/**
 * [Deskripsi]
 * Memindahkan blok pada tower yang satu ke tower yang lain
 * 
 * @author
 */
void moveDisk(Tower* src, Tower* dest)
{

}

/**
 * [Deskripsi]
 * Menyimpan game dengan posisi penyimpanan berdasarkan index
 * 
 * @author
 */
bool saveGame(Game *game, int index)
{

}

/**
 * [Deskripsi]
 * Memuat game yang terdapat pada save game berdasarkan index
 * 
 * @author
 */
Game loadGame(int index)
{

}

/**
 * [Deskripsi]
 * Menghapus data game yang telah tersimpan
 * 
 * @author
 */
int deleteGame(int index)
{

}

/**
 * [Deskripsi]
 * Titik masuk dari permainan
 * 
 * @author
 */
void gameStart(Tower *T)
{

}

/**
 * [Deskripsi]
 * Menjalankan lojik dari permainan
 * 
 * @author
 */
void *gameRun(Tower *T)
{

}

/**
 * [Deskripsi]
 * Menjalankan timer dari permainan
 * 
 * @author
 */
void *gameTimer(Tower *T)
{

}

/**
 * [Deskripsi]
 * Menyimpan skor dari permainan
 * 
 * @author
 */
void saveHighScore(Game game)
{
    
}

/**
 * [Deskripsi]
 * Menghapus semua skor yang tersimpan
 * 
 * @author
 */
void deleteAllHighScore()
{
    
}
