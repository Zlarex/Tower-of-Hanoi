/**
 * Kelompok 6
 * 
 * Anggota:
 * 201524003 - Diana Fauziah
 * 201524011 - Ihsan Fauzan Hanif
 * 201524014 - Muhammad Aziz Taufiqurrahman
 * 
 * game.h
 * Struktur data yang merepresentasikan sistem Game yang
 * dikhususkan untuk permainan Tower of Hanoi.
 */

#ifndef __GAME_HEADER__
#define __GAME_HEADER__

#include <stdbool.h>
#include "all.h"

#define MAX_LEVEL 5
#define MAX_SAVED_GAME 10
#define MAX_SAVED_SCORE 10

// Kondisi game
typedef enum _GameState {
    NONE,
    WIN,
    LOSE
} GameState;

// Tipe game yang dipilih
typedef enum _GameMode {
    ORIGINAL,
    PRACTICE
} GameMode;

// Sistem Game
typedef struct _Game {
    Tower right;
    Tower middle;
    Tower left;
    int moveCount;
    int towerLevel;
    int maxBlock;
    int score;
    int timeLeft;
    bool hasGameOver;
    bool isPaused;
    GameMode mode;
    GameState state;
    char playerName[50];
} Game;

/**
 * [Deskripsi]
 * Inisialisasi sistem Game, bertujuan untuk mengatur agar semua
 * informasi terkait dengan Game bernilai kosong
 * 
 * @author
 */
void createGame(Game *game);

/**
 * [Deskripsi]
 * Menu untuk memulai permainan baru
 * 
 * @author
 */
void menuPlayGame(Game *game);

/**
 * [Deskripsi]
 * Menu untuk memuat permainan lama (yang telah tersimpan)
 * 
 * @author
 */
void menuLoadGame(Game *game);

/**
 * [Deskripsi]
 * Menu untuk membuat permainan yang dikustomisasi oleh pemain
 * 
 * @author
 */
void menuPracticeGame(Game *game);

/**
 * [Deskripsi]
 * Menu untuk menampilkan top 10 pemain dengan skor tertinggi
 * 
 * @author
 */
void menuHighScore(Game *game);

/**
 * [Deskripsi]
 * Menu untuk menampilkan informasi mengenai game dan/atau developer
 * 
 * @author
 */
void menuCredits(Game *game);

/**
 * [Deskripsi]
 * Menu untuk keluar dari program
 * 
 * @author
 */
void menuExit(Game *game);

/**
 * [Deskripsi]
 * Menu sebagai tempat berhenti sesaat sebelum permainan dimulai
 * 
 * @author
 */
void menuLobby(Game *game);

/**
 * [Deskripsi]
 * Mendapatkan disk maksimal yang bisa dimasukkan berdasarkan level dari tower 
 * 
 * @author
 */
int getMaxDisk(int towerLevel);

/**
 * [Deskripsi]
 * Mendapatkan waktu maksimal yang bisa digunakan untuk bermain berdasarkan level dari tower
 * 
 * @author
 */
int getMaxTime(int towerLevel);

/**
 * [Deskripsi]
 * Mendapatkan pergerakan minimal yang bisa dilakukan untuk menyelesaikan permainan
 * 
 * @author
 */
int getMinMoves(int towerLevel);

/**
 * [Deskripsi]
 * Memindahkan blok pada tower yang satu ke tower yang lain
 * 
 * @author
 */
void moveDisk(Tower* src, Tower* dest);

/**
 * [Deskripsi]
 * Menyimpan game dengan posisi penyimpanan berdasarkan index
 * 
 * @author Ihsan Fauzan Hanif
 */
bool saveGame(Game *game, int index);

/**
 * [Deskripsi]
 * Memuat seluruh data permainan tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
void loadAllSaveGame(char* result, int max);

/**
 * [Deskripsi]
 * Memuat game yang terdapat pada save game berdasarkan index
 * 
 * @author Ihsan Fauzan Hanif
 */
Game loadGame(int index);

/**
 * [Deskripsi]
 * Menghapus data game yang telah tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
bool deleteGame(int index);

/**
 * [Deskripsi]
 * Titik masuk dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void gameBegin(Game *game);

/**
 * [Deskripsi]
 * Menampilkan output isi dari tower berdasarkan string.
 * 
 * @author Ihsan Fauzan Hanif
 */
void printTowerStr(char *str, int width);
/**
 * [Deskripsi]
 * Menampilkan tampilan dari tower
 * 
 * @author Ihsan Fauzan Hanif
 */
void printTower(Game* g);

/**
 * [Deskripsi]
 * Menjalankan lojik dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameRun(void *ptrGame);

/**
 * [Deskripsi]
 * Menjalankan timer dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameTimer(void *ptrGame);

/**
 * [Deskripsi]
 * Menyimpan skor dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void saveHighScore(Game game);

/**
 * [Deskripsi]
 * Menyortir isi dari file highscore
 * 
 * @author Ihsan Fauzan Hanif
 */
void sortHighScore(Game *game);

/**
 * [Deskripsi]
 * Menghapus semua skor yang tersimpan
 * 
 * @author Ihsan Fauzan Hanif
 */
bool deleteAllHighScore();

#endif
