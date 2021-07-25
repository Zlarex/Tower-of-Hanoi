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
#include <pthread.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

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
 * @author M Aziz Taufiqurrahman
 */
void menuPlayGame(Game *game)
{ 
	createGame(game);
	printSaveGame(); 
	printf("masukkan pilihan save game: "); 
	scanf("%d", &game->index); 
	game->index--; 
	fflush(stdin);
	printf ("Silakan, masukan nama anda : ");
	scanf("%[^\n]s", game->playerName); 
	fflush(stdin);
	menuLobby(game);
}

/**
 * [Deskripsi]
 * Menu untuk memuat permainan lama (yang telah tersimpan)
 * 
 * @author M Aziz Taufiqurrahman
 */
void menuLoadGame(Game *game) {
	int pilihan;
	
	printSaveGame(); 
	printf("masukkan pilihan game yang ingin dilanjutkan : ");  
	scanf ("%d", &pilihan); 
	*game = loadgame(--pilihan);
	menuLobby(game);
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
 * @author M Aziz Taufiqurrahman
 */
void menuHighScore(Game *game)
{
	char pilihan;
	printf ("Berikut ini merupakan daftar 10 pemain dengan nilai tertinggi : \n ");
	printHighScore();
	printf ("Hapus High Score? y/n ");
	scanf ("%c", &pilihan);
	switch (pilihan) {
		case 'y' : deleteAllHighScore(); break; 
		case 'n' : break;
		default : printf ("Anda memasukkan nilai yang salah :( ");
	}
	system("pause");
}

/**
 * [Deskripsi]
 * Menu untuk menampilkan informasi mengenai game dan/atau developer
 * 
 * @author
 */
void menuCredits(Game *game)
{

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
 * @author M Aziz Taufiqurrahman
 */
void menuLobby(Game *game) {
	int pilihan;
	printf ("1. Lanjutkan Permainan");
	printf ("2. Menu Utama");
	printf ("Masukkan pilihan Anda : ");
	scanf ("%d", &pilihan);
	switch (pilihan) {
		case 1 : gameEntry(game); break;
		case 2 : menuMain(game); break; 
		default : printf ("Mohon maaf Anda salah dalam input nilai :( ");
	}
}

/**
 * [Deskripsi]
 * Mendapatkan disk maksimal yang bisa dimasukkan berdasarkan level dari tower 
 * 
 * @author M Aziz Taufiqurrahman
 */
int getMaxDisk(int towerLevel) {
	switch (towerLevel) {
		case 1 : return 2; break;
		case 2 : return 3; break;
		case 3 : return 4; break;
		case 4 : return 5; break;
		case 5 : return 5; break;
	}
}

/**
 * [Deskripsi]
 * Mendapatkan waktu maksimal yang bisa digunakan untuk bermain berdasarkan level dari tower
 * 
 * @author M Aziz Taufiqurrahman
 */
int getMaxTime(int towerLevel) {
	switch (towerLevel){
		case 1 : return 30; break; 
		case 2 : return 60; break; 
		case 3 : return 100; break; 
		case 4 : return 300; break; 
		case 5 : return 150; break;
	}
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
 * @author Ihsan Fauzan Hanif
 */
bool saveGame(Game *game, int index)
{
    bool retVal = false;
    int maxSize = sizeof(*game) * MAX_SAVED_GAME;
    char *gameData = malloc(maxSize);
    memset(gameData, 0, maxSize);
    loadAllSaveGame(gameData, maxSize);
    
    index--; // index penyimpanan dimulai dari nol
    memcpy(gameData + (index * sizeof(*game)), game, sizeof(*game));
    FILE *file = fopen("save.dat", "wb");
    if (!file)
    {
        printf("Error: Unable to create the file");
        system("pause");
        exit(EXIT_FAILURE);
    }
    if (fwrite(gameData, maxSize, 1, file) == 1) retVal = true;
    fclose(file);
    free(gameData);
    return retVal;
}

/**
 * [Deskripsi]
 * Memuat seluruh data permainan tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
void loadAllSaveGame(char* result, int max)
{
    FILE *file = fopen("save.dat", "rb");
    if (file) fread(result, max, 1, file);
    fclose(file);
}

/**
 * [Deskripsi]
 * Memuat game yang terdapat pada save game berdasarkan index
 * 
 * @author Ihsan Fauzan Hanif
 */
Game loadGame(int index)
{
    Game retVal;
    memset(&retVal, 0, sizeof(retVal));
    int maxSize = sizeof(retVal) * MAX_SAVED_GAME;
    char *gameData = malloc(maxSize);
    
    index--;
    loadAllSaveGame(gameData, maxSize);
    memcpy(&retVal + (index * sizeof(retVal)), gameData, sizeof(retVal));
    free(gameData);
    return retVal;
}

/**
 * [Deskripsi]
 * Menghapus data game yang telah tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
bool deleteGame(int index)
{
    Game g;
    memset(&g, 0, sizeof(Game));
    return saveGame(&g, index);
}

/**
 * [Deskripsi]
 * Titik masuk dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void gameBegin(Game *game)
{
    game->hasGameOver = false;
    game->isPaused = false;
    game->maxBlock = 3;
    game->timeLeft = 10;

    pthread_t thGameRun, thGameTimer;
    pthread_create(&thGameRun, NULL, gameRun, NULL);
    pthread_create(&thGameTimer, NULL, gameTimer, NULL);
    pthread_join(thGameRun, NULL);
    pthread_join(thGameTimer, NULL);
}

/**
 * [Deskripsi]
 * Menjalankan lojik dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameRun(Game *game)
{
    while (true)
    {
        if (game->timeLeft == 0)
        {
            game->state = LOSE;
            break;
        }
        if (game->isPaused)
        {
            // pause game
            printf("Permainan Dijeda\n");
            system("pause");
        }
        else
        {
            showTowers();
            
        }
    }
    return NULL;
}

/**
 * [Deskripsi]
 * Menjalankan timer dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameTimer(Game *game)
{
    game->timeLeft++;
    while (game->timeLeft > -1)
    {
        if (!game->isPaused && game->mode == ORIGINAL) game->timeLeft--;
        Sleep(1);
    }
    return NULL;
}

/**
 * [Deskripsi]
 * Menyimpan skor dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void saveHighScore(Game game)
{
    int maxSize = sizeof(game) * MAX_SAVED_SCORE;
    Game HSdata[MAX_SAVED_SCORE];
    memset(&HSdata, 0, sizeof(HSdata));
    
    FILE *file = fopen("score.dat", "rb");
    if (file) fread(HSdata, maxSize, 1, file);
    fclose(file);

    memset(&HSdata[MAX_SAVED_SCORE - 1], 0, sizeof(HSdata[MAX_SAVED_SCORE - 1]));
    memcpy(&HSdata[MAX_SAVED_SCORE - 1], &game, sizeof(game));
    sortHighScore(HSdata);

    file = fopen("score.dat", "wb");
    if (!file) return;
    int code = fwrite(HSdata, sizeof(HSdata), 1, file);
    fclose(file);
}

/**
 * [Deskripsi]
 * Menyortir isi dari file highscore
 * 
 * @author Ihsan Fauzan Hanif
 */
void sortHighScore(Game *game)
{
    Game temp;
    int i, j;
    for (i = 0; i < MAX_SAVED_SCORE; i++)
    {
        for (j = 0; j < MAX_SAVED_SCORE; j++)
        {
            if (game[j].score > game[j - 1].score)
            {
                memset(&temp, 0, sizeof(Game));
                memcpy(&temp, &game[j], sizeof(Game));

                memset(&game[j], 0, sizeof(Game));
                memcpy(&game[j], &game[j - 1], sizeof(Game));
                
                memset(&game[j - 1], 0, sizeof(Game));
                memcpy(&game[j - 1], &temp, sizeof(Game));
            }
        }
    }
}

/**
 * [Deskripsi]
 * Menghapus semua skor yang tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
bool deleteAllHighScore()
{
    return remove("score.dat") == 0? true : false;
}
