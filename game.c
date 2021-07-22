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
	memset(game, 0, sizeof(Game)); //membuat semua game kosong/membentuk game baru
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
 * Diana Fauziah
 * 07/21/21
 */
void menuPracticeGame(Game *game)
{
	printf("-----------------MENU PRACTICE GAME---------------\n\n");
	
	while(true){
	system("cls");
	printf("/t/tMasukan Banyaknya disk pada permainan : ");
	scanf("%d", &game->towerLevel);
		if(game->towerLevel == 1 || game->towerLevel== 2 || game->towerLevel == 3 ||game->towerLevel == 4){
			menuLobby(&game);
			return;
		}	
	}
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
 * Diana Fauziah
 * 07/22/21
 */
void moveDisk(Tower* src, Tower* dest)
{
    int width = 0;
    pop(src, &width);
    push(dest, width);
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
    pthread_create(&thGameRun, NULL, gameRun, game);
    pthread_create(&thGameTimer, NULL, gameTimer, game);
    pthread_join(thGameRun, NULL);
    pthread_join(thGameTimer, NULL);
}

/**
 * [Deskripsi]
 * Menampilkan output isi dari tower berdasarkan string.
 * 
 * @author Ihsan Fauzan Hanif
 */
void printTowerStr(char *str, int width)
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		if (i == 0) continue;
		printf("%c", (int)*(str + i));
	}
	printf("\n");
}

/**
 * [Deskripsi]
 * Menampilkan tampilan dari tower
 * 
 * @author Ihsan Fauzan Hanif
 */
void printTower(Game* g)
{
	#define BLOCK 219
	#define UNDERLINE 196
	#define POLE 179
	int sizeEach = 2;
	int width = 3 + 3 + (g->maxBlock * (2 * sizeEach) * 3); // tower + padding + disk len (2 = tambahan kiri-kanan, 3 = banyak tower)

	//     --|--         --|--         --|--
	//   ----|----     ----|----     ----|----
	// ------|------ ------|------ ------|------
	
	// ---------|--------- ---------|--------- ---------|---------

	// ------------|------------ ------------|------------ ------------|------------

	//
	//   ----|---- ----|---- ----|----

	//   --|-- --|-- --|--
	// 1
	// 4 - 12 - 20 ==> 8
	// 
	// 2
	// 7 - 21 - 35 ==> 14
	//
	// 3
	// 10 - 30 - 50
	//
	// 4
	// 13
	int midPos = sizeEach * g->maxBlock + 1;
	int middlePos[3] = {
		midPos,
		midPos * 3,
		midPos * 5
	};

	char* output = malloc(width + 1);
	int height = g->maxBlock + 1;

	Address* diskLeft = &(g->left).top;
	Address* diskMiddle = &(g->middle).top;
	Address* diskRight = &(g->right).top;

	int heightDiskLeft = getDiskCount(&(g->left));
	int heightDiskMiddle = getDiskCount(&(g->middle));
	int heightDiskRight = getDiskCount(&(g->right));

	int i, j;
	for (i = height + 1; i > 0; i--)
	{
		*(output + width) = (char)0;
		memset(output, ' ', width);
		*(output + middlePos[0]) = *(output + middlePos[1]) = *(output + middlePos[2]) = POLE;
		if (i == 0 + 1)
		{
			memset(output, UNDERLINE, width);
		}
		else if (i > 0)
		{
			for (j = 0; j < 3; j++)
			{
				Address **diskPtr = (j == 0)? &diskLeft : (j == 1)? &diskMiddle : &diskRight;
				int *heightDisk = (j == 0)? &heightDiskLeft : (j == 1)? &heightDiskMiddle : &heightDiskRight;

				if (!(*diskPtr) || !(**diskPtr)) continue;
				if (i - 1 <= *heightDisk)
				{
					int blockLen = ((**diskPtr)->width * 2) + 1;
					int pos = middlePos[j] - (**diskPtr)->width * sizeEach;
					memset(output + pos, BLOCK, ((**diskPtr)->width * sizeEach) * 2 + 1);
					*diskPtr = &(**diskPtr)->next;
				}
			}
		}
		printTowerStr(output, sizeEach);
		// break;
	}
	free(&output);
	#undef BLOCK
	#undef POLE
}
/**
 * [Deskripsi]
 * Menjalankan lojik dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameRun(void *ptrGame)
{
    Game* game = (Game*) ptrGame;
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
void *gameTimer(void *ptrGame)
{
    Game* game = (Game*) ptrGame;
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
