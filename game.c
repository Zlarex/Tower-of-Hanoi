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
#define ESC 27		//klik esc

/**
 * [Deskripsi]
 * Inisialisasi sistem Game, bertujuan untuk mengatur agar semua
 * informasi terkait dengan Game bernilai kosong
 * 
 * @author
 * Diana Fauziah
 * 07/21/21
 */
void createGame(Game *game)
{
	game->left.top = NULL;
	game->right.top = NULL;
	game->middle.top = NULL;
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
 * Diana Fauziah
 * 07/21/21
 */
void menuExit(Game *game)
{
    char ch;
    printf("-------------------------------------------------\n");
    printf("|Apakah Anda yakin ingin meninggalkan permainan? |\n")
    printf("\n|  Tekan [ESC] untuk keluar                    |\n");
    printf("=================================================\n")
    do {
        ch = getch();
        if(ch == ESC){
        	return 0;
//            system("cls");
//            main();
        }
    } while(ch != ESC);
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

/**
 * [Deskripsi]
 * Menampilkan taktik bermain Tower of hanoi
 * @author 
 * Diana Fauziah
 * 07/22/21
 */
void ShowStep(Game *game, int choose){
	printf("===============================================================\n");
	printf("/t/t/t/t TAKTIK PERMAINAN TOWER OF HANOI\n");
	printf("===============================================================\n\n");
	
	if (choose == 1){
		printf("Level 1\n");
		printf("-------------------------------------------\n");
		printf("1. Gunakan rumus f(n) = 2^n-1), untuk menghitung jumlah minimal langkah\n");
		printf("2. untuk kasus ini terdapat 2 piringan berarti -> 2^2 - 1 = 3 (langkah)\n");
		printf("3. disk 1 -> tower C\n");
		printf("4. disk 2 -> tower B\n");
		printf("5. disk 1 -> tower B\n");
	}else if (choose == 2){
		printf("Level 2\n");
		printf("-------------------------------------------\n");
		printf("1. Gunakan rumus f(n) = 2^n-1), untuk menghitung jumlah minimal langkah\n");
		printf("2. untuk kasus ini terdapat 3 piringan berarti -> 2^3 - 1 = 7 (langkah)\n");
		printf("3. disk 1 -> tower C\n");
		printf("4. disk 2 -> tower B\n");
		printf("5. disk 1 -> tower B\n");
		printf("6. disk 3 -> tower C\n");
		printf("7. disk 1 -> tower A\n");
		printf("8. disk 2 -> tower C\n");
		printf("9. disk 1 -> tower C\n");
	}else if (choose == 3){
		printf("Level 3\n");
		printf("-------------------------------------------\n");
		printf("1. Gunakan rumus f(n) = 2^n-1), untuk menghitung jumlah minimal langkah\n");
		printf("2. untuk kasus ini terdapat 4 piringan berarti -> 2^4 - 1 = 15 (langkah)\n");
		printf("3. disk 1 -> tower C\n");
		printf("....................\n");
		printf("15. disk 1 -> tower B\n");
	}else if (choose == 4){
		printf("Level 4\n");
		printf("-------------------------------------------\n");
		printf("1. Gunakan rumus f(n) = 2^n-1), untuk menghitung jumlah minimal langkah\n");
		printf("2. untuk kasus ini terdapat 5 piringan berarti -> 2^5 - 1 = 31 (langkah)\n");
		printf("3. disk 1 -> tower C\n");
		printf("....................\n");
		printf("31. disk 1 -> tower B\n");
	}else if (choose == 5){
		printf("Level 5\n");
		printf("-------------------------------------------\n");
		printf("1. Gunakan rumus f(n) = 2^n-1), untuk menghitung jumlah minimal langkah\n");
		printf("2. untuk kasus ini terdapat 5 piringan berarti -> 2^5 - 1 = 31 (langkah)\n");
		printf("3. disk 1 -> tower C\n");
		printf("....................\n");
		printf("15. disk 1 -> tower B\n");
	}
}
