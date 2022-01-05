// TicTacToe.v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "TicTac.h"

int main()
{
    cout << "Tic Tac Toe!\n";

    TicTac t;
    t.startAttempt();
    cout << "\n--------\n";
    t.printPointers();
    t.printGraph();

}
