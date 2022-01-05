#include "TicTac.h"
#include <iostream>
using namespace std;

//mutator
//sets some movemnt outside the class .cpp but in main
void TicTac::setMove(int n, UserMove* m) {
	if (n >= 0 && n < 9) { //checks if pointer array is out of boundaries
		if (moves[n] == nullptr)//puts new value into pointer
			moves[n] = m;
		else {
			delete moves[n];
			moves[n] = m;
		}
	}
}

UserMove* TicTac::getMove(int n)const { //accessor
	if (n < 0 || n > 9)//checks bounds
		return nullptr;
	else
		return moves[n];
}

void TicTac::resetMoves() { //empties the array
	for (int i = 0; i < 9; i++) {
		if (moves[i] != nullptr) {
			delete moves[i];
			moves[i] = nullptr;
		}
	}
}



//should sort the array by row and columns
//first row and then column
//should be done so that veerything will be displayed in drawing later

void TicTac::bubbleSort(UserMove* m[], int l) {
	UserMove* temp;
	int temp1, temp2;
	char temp3;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l - 1; j++) {
			if ((m[j]->getRows() > m[j + 1]->getRows()) &&
				m[j]->getColumns() <= m[j + 1]->getColumns()) {

				temp1 = m[j]->getRows();
				temp2 = m[j]->getColumns();
				temp3 = m[j]->getUserMove();

				m[j]->setRows(m[j+1]->getRows());
				m[j]->setColumns(m[j+1]->getColumns());
				m[j]->setUserMove(m[j+1]->getUserMove());

				m[j+1]->setRows(temp1);
				m[j+1]->setColumns(temp2);
				m[j+1]->setUserMove(temp3);
			}

			else if ((m[j]->getRows() == m[j + 1]->getRows()) &&
				m[j]->getColumns() > m[j + 1]->getColumns()) {

				temp1 = m[j]->getRows();
				temp2 = m[j]->getColumns();
				temp3 = m[j]->getUserMove();

				m[j]->setRows(m[j + 1]->getRows());
				m[j]->setColumns(m[j + 1]->getColumns());
				m[j]->setUserMove(m[j + 1]->getUserMove());

				m[j+1]->setRows(temp1);
				m[j+1]->setColumns(temp2);
				m[j+1]->setUserMove(temp3);
			}
		}
	}
}


//starts the overall performance of app in class
//might be in the main()
//sets the values into pointer array
void TicTac::startAttempt() {
	UserMove* ptr; //poiter
	//user varaibles
	char userInput; 
	int u1 = 1, u2 = 1;

	bool found = false;

	int allowedMoves[9][2] = {  {1, 1}, {1, 2}, {1, 3},
								{2, 1}, {2, 2}, {2, 3},
								{3, 1}, {3, 2}, {3, 3} };



	//runs within the bounds of the array
	int i = 0;
	while (i < 9) {
		found = false; //always has to reset to false

		cout << i + 1 << ". Your move (rows, columns): ";
		cin >> u1;
		cin >> u2;

		//check that users enters the value withing allowed bounds
		if ((u1 < 0 || u1 > 4) || (u2 < 0 || u2 > 4)) {
			//use throw statement <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			cout << "Invalid numbered entered for row or column.(has to be 1-3)\n";
			
		}
		else {

			//checks if moves are repeated and clears array with that specific movement
			for (int j = 0; j < 9; j++) {
				if (u1 == allowedMoves[j][0] && u2 == allowedMoves[j][1]) {
					allowedMoves[j][0] = NULL; //clears allowed move from list
					allowedMoves[j][1] = NULL;
					found = true; //sets that entered can be made
					
					//puts automatically x or o as values based on odd or even number of moves
					if (i % 2 == 0) {
						ptr = new UserMove('x', u1 - 1, u2 - 1);
					}
					else {
						ptr = new UserMove('o', u1 - 1, u2 - 1);
					}

					//sets values into pointer array in function
					setMove(i, ptr);

					i++;
				}
				
			}

			if (!found)
				cout << ">>>ERROR: Repeated move.\n";
			
		}
		
	}
	
}

//works but moves to be set at correct placement
//moves[i]->getRows() ....  <<<<<<<<<<<<<<<<<<<<<<<<<<<<
void TicTac::printGraph() {
	bubbleSort(moves, 9);
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0)
			cout << endl;
		cout << moves[i]->getUserMove() << " ";
	}
}

//prints everything thats in pointer
void TicTac::printPointers() {
	for (int i = 0; i < 9; i++) {
		cout << "Charac: \t" << moves[i]->getUserMove() << endl;
		cout << "  Rows: \t" << moves[i]->getRows() << endl;
		cout << "Column: \t" << moves[i]->getColumns() << endl;
		cout << "===========================================\n";
	}

}


//constructor that sets array to null value
TicTac::TicTac() {
	for (int i = 0; i < 9; i++)
		moves[i] = nullptr;
}
