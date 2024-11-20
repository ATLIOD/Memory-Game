#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	//functions
	void fillBoard(char[4][4]);
	void fillBoard(char[4][4], char);
	void print(char[4][4]);
	bool isEqual(char, char);
	void changeCard(char[4][4], int[2], char);
	void clearWrongPositions(char[4][4], int[2], int[2]);
	bool isAllFound(char[4][4],char[4][4]);

	//varialbes/arrays
	char rawBoard[4][4];
	char censoredBoard[4][4];
	char foundBoard[4][4];
	char firstCard=0;
	int firstCardPos[2];
	char secondCard=9;
	int secondCardPos[2];

	fillBoard(rawBoard);
	fillBoard(foundBoard, '*');
	fillBoard(censoredBoard, '*');

	while (!isAllFound(foundBoard, rawBoard))
	{
		print(censoredBoard);

		cout << "Enter the row (1 to 4) and col (1 to 4) position of the pair: " << endl;
		cin >> firstCardPos[0] >> firstCardPos[1];
		while (firstCardPos[0] < 1 || firstCardPos[1] < 1 || firstCardPos[0] > 4 || firstCardPos[1] > 4)
		{
			cout << "invalid position. try again: " << endl;
			cin >> firstCardPos[0] >> firstCardPos[1];
		}
		firstCardPos[0] -= 1;
		firstCardPos[1] -= 1;

		firstCard = rawBoard[firstCardPos[0]][firstCardPos[1]];

		changeCard(censoredBoard, firstCardPos, firstCard);

		print(censoredBoard);

		cout << "Enter the row (1 to 4) and col (1 to 4) position of the pair: " << endl;
		cin >> secondCardPos[0] >> secondCardPos[1];
		while (secondCardPos[0] < 1 || secondCardPos[1] < 1 || secondCardPos[0] > 4 || secondCardPos[1] > 4 || (secondCardPos[0]-1 == firstCardPos[0] && secondCardPos[1]-1 == firstCardPos[1]))
		{
			cout << "invalid position. try again: " << endl;
			cin >> secondCardPos[0] >> secondCardPos[1];
		}
		secondCardPos[0] -= 1;
		secondCardPos[1] -= 1;

		secondCard = rawBoard[secondCardPos[0]][secondCardPos[1]];

		changeCard(censoredBoard, secondCardPos, secondCard);

		print(censoredBoard);

		if (isEqual(firstCard, secondCard))
		{
			changeCard(foundBoard, firstCardPos, firstCard);
			changeCard(foundBoard, secondCardPos, secondCard);
			cout << "\nYou Found a Match! Good Job!\n";
		}
		else
		{
			cout << "Pair does not match. Select again: \n";
			clearWrongPositions(censoredBoard, firstCardPos, secondCardPos);
		}

		firstCard = 0;
		secondCard = 5;
		firstCardPos[0] = -1;
		firstCardPos[1] = 9;
		secondCardPos[0] = 9;
		secondCardPos[1] = -1;

	}
	cout << "You have found all pairs good job!!";
	print(foundBoard);
	cout << endl << "Congratulations!!";

	return 0;
}
void fillBoard(char board[4][4]) 
{
	bool sequentialSearch(char[4][4], int); //sequential search to search arrays
	char randHolder; //variable to hold random int 

	srand(time(NULL)); //seeds random number generator to make sure that numbers are different this time

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{

			randHolder = '0' + (1 + rand() % 8);

			while (sequentialSearch(board, randHolder))
			{
				randHolder = '0'+(1 + rand() % 8);
			}

			board[row][col] = randHolder;
		}
	}
}
void fillBoard(char board [4][4], char val)

{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			board[row][col] = val;
		}
	}
}
bool sequentialSearch(char board[4][4], int rand)
{
	int count = 0;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (board[row][col] == rand)
			{
				count++;
			}
			if (count > 1)
			{
				return true;
			}
		}
	}
	return false;
}
void print(char board[4][4])
{
	cout << endl;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
bool isEqual(char firstCard, char secondCard)
{
	if (firstCard == secondCard)
	{
		return true;
	}
	else
		return false;
}
void changeCard(char board[4][4], int pos[2], char val)
{
	board[pos[0]][pos[1]] = val;
}
void clearWrongPositions(char board [4][4],int firstPos[2], int secondPos[2]) 
{
	changeCard(board, firstPos, '*');
	changeCard(board, secondPos, '*');
}
bool isAllFound(char found[4][4], char raw[4][4])
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (found[row][col] != raw[row][col])
			{
				return false;
			}
		}
	}
	return true;
}