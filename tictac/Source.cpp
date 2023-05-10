#include<iostream>
using namespace std;
enum PlayerTurn { FIRST_PLAYER = 1, SECOND_PLAYER = 2 };
enum GameStatus { DRAW, WIN, IN_PROGRESS };
class GameBoard
{
private:
	char data[3][3];
	int validMovesCount = 0;
	GameStatus gameStatus = IN_PROGRESS;
public:
	GameBoard()
	{
		int a = 49;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				data[i][j] = a;
				a++;
			}
		}
	}
	void displayBoard()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	void markBoard(char pos, char playerSymbol)
	{
		int rows;
		int cols;
		int a = ((int)pos - 48) - 1;
		rows = int(a) / 3;
		cols = int(a) % 3;
		data[rows][cols] = playerSymbol;
	}
	bool isValidPosition(char pos)
	{
		return (pos >= '1' && pos <= '9');
	}
	bool isAlreadyMarked(char pos)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (data[i][j] == pos)
				{
					return false;
				}
			}
		}
		return true;
	}
	int getValidMovesCount()
	{
		return validMovesCount;
	}
	GameStatus getGameStatus()
	{
		validMovesCount++;
		for (int w = 0; w < 3; w++)
		{
			if (data[w][0] == data[w][1] && data[w][1] == data[w][2])
			{
				return WIN;
			}
			else if (data[0][w] == data[1][w] && data[1][w] == data[2][w])
			{
				return WIN;
			}
		}
		if (data[0][0] == data[1][1] && data[1][1] == data[2][2])
		{

			return WIN;
		}
		if (data[0][2] == data[1][1] && data[1][1] == data[2][0])
		{
			return WIN;
		}

		else
		{
			return IN_PROGRESS;
		}
	}
};
class TicTacToe
{
	GameBoard board;
	GameStatus gs = IN_PROGRESS;
	PlayerTurn curr = FIRST_PLAYER;
	char symb = 0;
public:
	void playGame()
	{
		char player1symbol;
		char player2symbol;
		cout << "Enter Player 1 Symbol : ";
		cin >> player1symbol;
		while (player1symbol >= '1' && player1symbol <= '9')
		{
			cout << "Please Enter Valid player 1 symbol :";
			cin >> player1symbol;
		}
		cout << "Enter Player 2 Symbol : ";
		cin >> player2symbol;
		while (player2symbol >= '1' && player2symbol <= '9' || player1symbol == player2symbol)
		{
			cout << "Please Enter Valid player 2 symbol :";
			cin >> player2symbol;
		}

		char pos;
		board.displayBoard();
		symb = player1symbol;
		do
		{
			int a;
			cout << "Player " << curr << " Turn : Enter cell # : ";
			cin >> pos;
			while (!(board.isValidPosition(pos)) || (board.isAlreadyMarked(pos)))
			{
				cout << "Enter valid postion : ";
				cin >> pos;
			}
			board.markBoard(pos, symb);
			board.displayBoard();

			gs = board.getGameStatus();
			a = board.getValidMovesCount();
			if (a > 8 && gs != WIN)
			{
				gs = DRAW;
			}
			if (gs == WIN)
			{
				cout << "Game won by player : " << curr << endl;
			}
			if (gs == DRAW)
			{
				cout << "Game draw : " << endl;
			}
			curr = (curr == FIRST_PLAYER ? SECOND_PLAYER : FIRST_PLAYER);

			symb = (symb == player1symbol ? player2symbol : player1symbol);
		} while (gs == IN_PROGRESS);
	}

};
int main()
{
	TicTacToe a;
	a.playGame();
	return 0;
}