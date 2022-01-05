#pragma once

class UserMove {
private:	
	char user;
	int row;
	int column;
public:
	void setUserMove(char u);
	char getUserMove()const;
	void setRows(int x);
	int getRows()const;
	void setColumns(int y);
	int getColumns()const;
	UserMove(char u, int x, int y);
};