#include<iostream>
using namespace std;

char board[4][4] = { { '.', ',', ',', '.' }, { ',', '-', '-', ',' }, { ',', '-', '-', ',' }, { '.', ',', ',', '.' } };
int choice;
char turn = 'X';
int row = 0, col = 0;
bool draw = false;

void display_board()
{
	system("cls");
	cout << "\nWelcome to Connect 4 Game \nProgrammer: M.Somaan Javed (042)\n\n";
	cout << "1st Player [X] \n2nd Player [O]\n\n";
	cout << "Select Coloumn 1 to 4: \n \n";

	cout << "  1     2     3     4 \n";
	cout << "     |     |     |\n";
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |  " << board[0][3] << endl;
	cout << "_____|_____|_____|_____\n";
	cout << "     |     |     |\n";
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |  " << board[1][3] << endl;
	cout << "_____|_____|_____|_____\n";
	cout << "     |     |     |\n";
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |  " << board[2][3] << endl;
	cout << "_____|_____|_____|_____\n";
	cout << "     |     |     |\n";
	cout << "  " << board[3][0] << "  |  " << board[3][1] << "  |  " << board[3][2] << "  |  " << board[3][3] << endl;
	cout << "     |     |     |\n\n";
	return;
}

void player_turn()
{
	if (turn == 'X')
		cout << "Player1[X] turns: ";
	if (turn == 'O')
		cout << "Player2[O] turns:";

	cin >> choice;
	if (choice == 1)
	{
		if (board[3][0] != 'X' && board[3][0] != 'O')
		{
			row = 3; col = 0;
		}
		else if (board[2][0] != 'X' && board[2][0] != 'O')
		{
			row = 2; col = 0;
		}
		else if (board[1][0] != 'X' && board[1][0] != 'O')
		{
			row = 1; col = 0;
		}
		else if (board[0][0] != 'X' && board[0][0] != 'O')
		{
			row = 0; col = 0;
		}
	}
	else if (choice == 2)
	{
		if (board[3][1] != 'X' && board[3][1] != 'O')
		{
			row = 3; col = 1;
		}
		else if (board[2][1] != 'X' && board[2][1] != 'O')
		{
			row = 2; col = 1;
		}
		else if (board[1][1] != 'X' && board[1][1] != 'O')
		{
			row = 1; col = 1;
		}
		else if (board[0][1] != 'X' && board[0][1] != 'O')
		{
			row = 0; col = 1;
		}
	}
	else if (choice == 3)
	{
		if (board[3][2] != 'X' && board[3][2] != 'O')
		{
			row = 3; col = 2;
		}
		else if (board[2][2] != 'X' && board[2][2] != 'O')
		{
			row = 2; col = 2;
		}
		else if (board[1][2] != 'X' && board[1][2] != 'O')
		{
			row = 1; col = 2;
		}
		else if (board[0][2] != 'X' && board[0][2] != 'O')
		{
			row = 0; col = 2;
		}
	}
	else if (choice == 4)
	{
		if (board[3][3] != 'X' && board[3][3] != 'O')
		{
			row = 3; col = 3;
		}
		else if (board[2][3] != 'X' && board[2][3] != 'O')
		{
			row = 2; col = 3;
		}
		else if (board[1][3] != 'X' && board[1][3] != 'O')
		{
			row = 1; col = 3;
		}
		else if (board[0][3] != 'X' && board[0][3] != 'O')
		{
			row = 0; col = 3;
		}
	};


	if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "Illegal Operation \n";
		player_turn();

	}
	return;
}


bool gameover()
{
	for (int i = 0; i < 4; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] || board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i])
			return false;
	}

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] || board[0][3] == board[1][2] && board[0][3] == board[2][1] && board[0][3] == board[3][0])
		return false;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;
		}
	}

	draw = true;
	return false;
}


int main()
{
	while (gameover())
	{
		display_board();
		player_turn();
		display_board();

	}


	if (turn == 'X' && draw == false)
		cout << "Player 2[0] Wins \n";
	else if (turn == 'O' && draw == false)
		cout << "Player 1[X] Wins \n";
	else
		cout << "Game Draw \n";


	system("pause");
	return 0;

}