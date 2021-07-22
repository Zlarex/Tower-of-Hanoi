/**
 * Kelompok 6
 * 
 * Anggota:
 * 201524003 - Diana Fauziah
 * 201524011 - Ihsan Fauzan Hanif
 * 201524014 - Muhammad Aziz Taufiqurrahman
 * 
 * main.c
 * Kode program utama
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "include/all.h"

int main()
{
	Game g;
	Tower t1, t2, t3;
	createTower(&t1);
	createTower(&t2);
	createTower(&t3);
	
	// g.hasGameOver = false;
	// g.score = 100;
	 g.maxBlock = 3;
	// g.moveCount = 10;
	// memcpy(g.playerName, "ihsan", 5);
	// g.timeLeft = 10;
	// g.towerLevel = 1;

	// saveGame(&g, 1);
	// Game g2 = loadGame(1);
	// g2.score = 1000;
	push(&t1, 3);
	push(&t1, 2);
	push(&t1, 1);
	push(&t2, 3);
	push(&t3, 3);
	g.right = t3;
	g.middle = t2;
	g.left = t1;
	// saveHighScore(g);
	// saveHighScore(g2);
	printTower(&g);
	return 0;
}
