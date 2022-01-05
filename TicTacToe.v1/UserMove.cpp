#include "UserMove.h"

void UserMove::setUserMove(char u) {
	user = u;
}

char UserMove::getUserMove()const {
	return user;
}

void UserMove::setRows(int x) {
	if (x >= 0 && x < 3)
		row = x;
}

int UserMove::getRows()const {
	return row;
}

void UserMove::setColumns(int y) {
	if (y >= 0 && y < 3)
		column = y;
}

int UserMove::getColumns()const {
	return column;
}

UserMove::UserMove(char u, int x, int y) {
	setUserMove(u);
	setRows(x);
	setColumns(y);
}