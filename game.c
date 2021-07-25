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

#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>
#include <unistd.h>

#include "include/all.h"
#define ESC 27		//klik esc
#define ENTER 13

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
 * Inisialisasi sistem game dan threading
 * 
 * @author
 */
void createRunner(Runner *runner)
{
	memset(runner, 0, sizeof(*runner));
}

/**
 * [Deskripsi]
 * Menu utama dalam permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void menuMain(Game *game)
{
	bool showInvalidMsg = false;
	void (*menuSelect[6])(Game*) = {
		menuPlayGame,
		menuLoadGame,
		menuPracticeGame,
		menuHighScore,
		menuCredits,
		menuExit
	};
	while (true)
	{
		system("cls");
		printf("-------------------------------------------------\n");
		printf("\t\tTower of Hanoi\n");
		printf("-------------------------------------------------\n");
		printf("\n[1]. Permainan Baru\n");
		printf("[2]. Lanjutkan Permainan\n");
		printf("[3]. Permainan Kustom\n");
		printf("[4]. Skor Tertinggi\n");
		printf("[5]. Kredit\n");
		printf("[6]. Keluar\n");

		if (showInvalidMsg)
		{
			printf("\nInput tidak valid!\n");
			showInvalidMsg = false;
		}
		printf("\nInput: ");
		int input = 0;
		scanf("%d", &input);
		input--;
		if (input < 0 || input > 5) showInvalidMsg = true;
		else return menuSelect[input](game);
	}
}

/**
 * [Deskripsi]
 * Menu untuk memulai permainan baru
 * 
 * @author M Aziz Taufiqurrahman
 */
void menuPlayGame(Game *game)
{
	char nama;
	printf ("Silakan, masukan nama anda : ");
	scanf ("%c", &nama);
	gameBegin ();
}

/**
 * [Deskripsi]
 * Menu untuk memuat permainan lama (yang telah tersimpan)
 * 
 * @author M Aziz Taufiqurrahman
 */
void menuLoadGame(Game *game) {
	printf ("Silakan melanjutkan permainanmu :) ");
	loadGame ();
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
	printf("\t\tMasukan Banyaknya disk pada permainan : ");
	scanf("%d", &game->towerLevel);
		if(game->towerLevel == 1 || game->towerLevel== 2 || game->towerLevel == 3 ||game->towerLevel == 4){
			menuLobby(game);
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

	sortHighScore();
   
    FILE *tampil;
    struct saveHighScore data;
    
    tampil = fopen("KumpulanSkor.txt", "rb");
    
    while (!feof(tampil)) {
        fscanf(tampil, "%s - %d\n", &data.NamaPemain, &data.skor);
        printf("Papan Peringkat\n");
        printf("%s - %d\n\n", data.NamaPemain, data.skor);
	}
    
	system("pause"); 
	//harusnya ada void menu utama 
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
	printf("\t\t\t\t TOWER OF HANOI\n");
	printf("***********************************************************************************\n\n");
	printf("\t\t Permainan yang bertujuan untuk melatih kemampuan\n");
	printf("\t\t matematis anda dalam memperhitungkan langkah untuk\n");
	printf("\t\t menyelesaikan permasalahan yang dilakukan dengan cara\n");
	printf("\t\t memindahkan seluruh disk pada tower yang ada di ujung\n");
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
    printf("|Apakah Anda yakin ingin meninggalkan permainan? |\n");
    printf("\n|  Tekan [ESC] untuk keluar                    |\n");
    printf("=================================================\n");
    do {
        ch = getch();
        if(ch == ESC){
        	exit(0);
//            system("cls");
//            main();
        }
    } while(ch != ESC);
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
	printf ("2. Keluar Permainan");
	printf ("Masukkan pilihan Anda : ");
	scanf ("%d", &pilihan);
	switch (pilihan) {
		case '1' : gameRun(); break;
		case '2' : saveGame (); break; 
		default : printf ("Mohon maaf Anda salah dalam input nilai :( ");
	}
}

/**
 * [Deskripsi]
 * Menu untuk memulai permainan baru
 * 
 * @author Ihsan Fauzan Hanif
 */
void menuPauseGame(Game *game)
{
	game->isPaused = true;
	system("cls");
	printf("-------------------------------------------------\n");
	printf("\t\tTower of Hanoi\n");
	printf("-------------------------------------------------\n\n\n");
	printTower(game);
	printf("\n[GAME DIJEDA]\n");
	if (game->mode == ORIGINAL) printf("\nWaktu tersisa: %d detik", game->timeLeft);	
	printf("\nTekan 'Enter' untuk melanjutkan");
	while (true)
	{
		fflush(stdin);
		char input = getch();
		if ((int)input == ENTER)
		{
			game->isPaused = false;
			break;
		}
		else if ((int)input == ESC)
		{
			game->state = LOSE;
			game->score = 0;
			break;
		}
	}
}

/**
 * [Deskripsi]
 * Menu untuk memulai permainan baru
 * 
 * @author Ihsan Fauzan Hanif
 */
void menuShowStep(Game *game)
{
	system("cls");
	ShowStep(game, game->towerLevel);
	printf("\n");
	printf("\nTekan 'Enter' untuk melanjutkan");
	while (true)
	{
		fflush(stdin);
		char input = getch();
		if ((int)input == ENTER) break;
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
 * @author
 */
int getMaxTime(int towerLevel) {
	switch (towerLevel){
		case 1 : return 30; break; 
		case 2 : return 60; break; 
		case 3 : return 75; break; 
		case 4 : return 90; break; 
		case 5 : return 90; break;
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
	return 1 << towerLevel - 1;
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
void gameEntry(Game *game)
{
    game->hasGameOver = false;
    game->isPaused = false;
    game->timeLeft = 	10;

	int i;
	for (i = game->maxBlock; i > 0; i--) push(&game->left, i);

    pthread_t thGameRun, thGameTimer;
	Runner runner;
	createRunner(&runner);
	runner.game = &game;
	runner.threadGame = &thGameRun;
	runner.threadTimer = &thGameTimer;

    pthread_create(&thGameRun, NULL, gameRun, &runner);
    pthread_create(&thGameTimer, NULL, gameTimer, &runner);
    pthread_join(thGameRun, NULL);
    pthread_join(thGameTimer, NULL);

	printf("\n[Permainan Berakhir]\n\n");
	printf(game->state == WIN? "Anda Menang!\n" : "Anda Kalah!\n");
	switch(game->state)
	{
		case WIN:
			if (game->mode == ORIGINAL)
			{
				game->score += (game->towerLevel * 10) + game->timeLeft;
				printf("Skor Anda: %d\n", game->score);
				if (game->towerLevel < 5)
				{
					saveGame(game, 0);
					printf("Mainkan level berikutnya? [Y/N]");
					char input = (char)0;
					scanf("%c", &input);
					fflush(stdin);

					if (input == 'Y' || input == 'y')
					{
						game->towerLevel++;
						return menuLobby(game);
					}
				}
				else
				{
					printf("Selamat! Anda telah menyelesaikan semua level\n");
					printf("Tekan tombol apapun untuk melanjutkan");
					getch();
					fflush(stdin);
				}
			}
			else
			{
				printf("Ulangi permainan? [Y/N]");
				char input = (char)0;
				scanf("%c", &input);
				fflush(stdin);

				if (input == 'Y' || input == 'y') return menuLobby(game);
			}
			return menuMain(game);
		case LOSE:
			if (game->mode == ORIGINAL)
			{
				printf("Skor Anda: %d\n", game->score);
				deleteGame(game->index);
				printf("Permainan tidak dapat diulangi.\n");
				printf("Tekan tombol apapun untuk melanjutkan");
				getch();
				fflush(stdin);
			}
			else
			{
				printf("Ulangi permainan? [Y/N]");
				char input = (char)0;
				scanf("%c", &input);
				fflush(stdin);

				if (input == 'Y' || input == 'y') return menuLobby(game);
			}
			return menuMain(game);
	}
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
	#define UI_BLOCK 219
	#define UI_GROUND 196
	#define UI_POLE 179
	int sizeEach = 2;
	int width = 3 + 3 + (g->maxBlock * (2 * sizeEach) * 3); // tower + padding + disk len (2 = tambahan kiri-kanan, 3 = banyak tower) 
	// posisi tengah dari tiang (3 disk):
	// 
	// lebar: 1
	// ---|--- ---|--- ---|---
	// 4 - 12 - 20
	// 
	// lebar: 2
	// ------|------ ------|------ ------|------
	// 7 - 21 - 35
	//
	// lebar: 3
	// ---------|--------- ---------|--------- ---------|---------
	// 10 - 30 - 50
	//
	// lebar: 4
	// ------------|------------
	// 13
	//
	// rumus: sizeEach * maxBlock + 1
	int midPos = sizeEach * g->maxBlock + 1;
	int middlePos[3] = {
		midPos - 1,
		midPos * 3 - 1,
		midPos * 5 - 1
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
		if (i == 0 + 1)
		{
			memset(output, UI_GROUND, width);
			*(output + middlePos[0]) = '1';
			*(output + middlePos[1]) = '2';
			*(output + middlePos[2]) = '3';
		}
		else if (i > 0)
		{
			*(output + middlePos[0]) = *(output + middlePos[1]) = *(output + middlePos[2]) = UI_POLE;
			for (j = 0; j < 3; j++)
			{
				Address **diskPtr = (j == 0)? &diskLeft : (j == 1)? &diskMiddle : &diskRight;
				int *heightDisk = (j == 0)? &heightDiskLeft : (j == 1)? &heightDiskMiddle : &heightDiskRight;

				if (!(*diskPtr) || !(**diskPtr)) continue;
				if (i - 1 <= *heightDisk)
				{
					int blockLen = ((**diskPtr)->width * 2) + 1;
					int pos = middlePos[j] - (**diskPtr)->width * sizeEach;
					memset(output + pos, UI_BLOCK, ((**diskPtr)->width * sizeEach) * 2 + 1);
					*diskPtr = &(**diskPtr)->next;
				}
			}
		}
		printTowerStr(output, sizeEach);
		// break;
	}
	free(&output);
	#undef UI_BLOCK
	#undef UI_POLE
	#undef UI_GROUND
}
/**
 * [Deskripsi]
 * Menjalankan lojik dari permainan
 * 
 * @author Ihsan Fauzan Hanif
 */
void *gameRun(void *argsData)
{
	bool showInvalidMsg = false;
	Runner* runner = (Runner*)argsData;
    Game* game = *(runner->game);
	game->state = NONE;
    while (true)
    {
		system("cls");
		printf("-------------------------------------------------\n");
		printf("\t\tTower of Hanoi\n");
		printf("-------------------------------------------------\n\n\n");
		printTower(game);
        if (game->timeLeft == 0 && game->mode == ORIGINAL) game->state = LOSE;
		
		if (game->state != NONE) break;
        if (game->isPaused) menuPauseGame(game);
        else
        {
			printf("\n[P] Pause Game\n");
			if (game->mode == PRACTICE)
			{
				printf("[H] Show hint\n");
				printf("[Q] Menyerah\n");
			}
			printf("Masukkan 2 nomor Tower untuk memindahkan Disk\n");
			if (showInvalidMsg)
			{
				printf("\nInput tidak valid!\n");
				showInvalidMsg = false;
			}
			printf("\nInput: ");
			char input[10] = {'\000'};
			fgets(input, 10, stdin);
			fflush(stdin);

			input[strlen(input) - 1] = (char)0;
			if (game->mode == PRACTICE)
			{
				if (strcmp(input, "P") == 0 || strcmp(input, "p") == 0)
				{
					game->isPaused = true;
					continue;
				}
				if (strcmp(input, "H") == 0 || strcmp(input, "h") == 0)
				{
					menuShowStep(game);
					continue;
				}
				if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
				{
					game->state = LOSE;
					continue;
				}
			}

			char *pSrc = strtok(input, " ");
			char *pDest = strtok(NULL, " ");

			int src = atoi(pSrc);
			int dest = atoi(pDest);
			if (src < 1 || src > 3 || dest < 1 || dest > 3)
			{
				showInvalidMsg = true;
				continue;
			}

			Tower *from = src == 1? &game->left : src == 2? &game->middle : &game->right;
			Tower *to = dest == 1? &game->left : dest == 2? &game->middle : &game->right;

			int topSrc = from->top? from->top->width : 0;
			int topDest = to->top? to->top->width : 0;
			if (topSrc > 0 && topSrc < topDest || topDest == 0 && topSrc != topDest)
			{
				moveDisk(from, to);
				if (getDiskCount(&game->right) == game->maxBlock) game->state = WIN;
			}
			else showInvalidMsg = true;
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
void *gameTimer(void *argsData)
{
	Runner *runner = (Runner*) argsData;
	Game* game = *(runner->game);

    game->timeLeft++;
    while (game->timeLeft > -1 && game->state == NONE)
    {
        if (!game->isPaused && game->mode == ORIGINAL) game->timeLeft--;
        sleep(1);
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
	printf("\t\t\t\t TAKTIK PERMAINAN TOWER OF HANOI\n");
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

/**
 * [Deskripsi]
 * Inisialisasi pengaturan sistem pada game
 * 
 * @author Ihsan Fauzan Hanif
 */
void initializeGameSystem(Game* game)
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	createGame(game);
}
