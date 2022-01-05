#pragma once
#include "UserMove.h"

class TicTac {
private:
	UserMove* moves[9];

public:
	void setMove(int n, UserMove* m);
	UserMove* getMove(int n)const;
	void resetMoves();
	void startAttempt();

	void bubbleSort(UserMove* moves[], int l = 9);

	void printPointers();

	void printGraph();

	TicTac();
};