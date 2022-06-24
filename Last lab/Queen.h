#pragma once
#include <vector>

class Board
{
protected:
	std::vector<std::vector<int>> board;
	int size;
	bool solve;
public:
	Board(int _size):board(_size, std::vector<int>(_size, 0))
	{
		solve = false;
		size = _size;
	}
	void place(int i, int j)
	{
		board[i][j] = -1;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				std::cout << board[i][j] << " ";
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	void max(int& k, int& h)
	{
		int max = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (max < board[i][j])
				{
					max = board[i][j];
					k = i;
					h = j;
				}
	}
	bool isEmpty()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (board[i][j] == -1) return false;
	}
	void find_best_place(int k, int h)
	{
		if(k<size)
		{
			if(h<size)
			{
				if (board[k][h] == -1)
				{
					for (int i = 0; i < size; i++)
					{
						for (int j = 0; j < size; j++)
						{
							if (board[i][j] != -1 && board[i][j] != -2)
							{
								if ((k - h) == (i - j) || (k + h) == (i + j) || k == i || h == j) board[i][j]++;
							}
						}
					}
				}
				find_best_place(k, h + 1);
			}
			find_best_place(k + 1, 0);
		}
	}
	void normalize()
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				if (board[i][j] != -1 && board[i][j] != -2) 
					board[i][j] = 0;
	}
};

class Queen: public Board
{
public:
	Queen(int size) :Board(size) {};
	int place_queen(int &count)
	{
		find_best_place(0,0);
		int k = 0, h = 0;
		max(k, h);
		print();
		board[k][h] = -2;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] != -2)
				{
					if ((k - h) == (i - j) || (k + h) == (i + j) || k == i || h == j) board[i][j] = 0;
				}
			}
		}
		normalize();
		if (!isEmpty())
		{
			count++;
			place_queen(count);
		}
		else return count;
	}
};

