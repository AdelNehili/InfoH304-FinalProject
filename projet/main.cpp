#include "board.h"
#include <string>
#include <iostream>
using namespace std;

// player 1 : 1 in code  -> O as graphical representation
// Player 2 : -1 in code -> X as graphical representation

// short sequence 1 to help debugging : f5, d6, c5, f4, e3, f6, g5, e6, e7
// short sequence 2 to help debugging : d3, c5, d6, e3, b4, c3, d2, c4, f4

int main()
{
	Board board;
	board.printBoard();
	int player = 1;
	string playerID;
	while (!board.isGameOver()) {
		if (player == 1) {
			playerID = "1 (X)";
		} else{
			playerID = "2 (O)";
		}
		while(true) {
			cout << "Turn of player " << playerID << " : ";
			string position;
			cin >> position;
			if (position == "00" && !board.validMoveExists(player)) {
				cout << "player " << playerID << " skipped his turn ";
			} else {
				int col = (int)position[0] - (int)('a');
				int row = (int)position[1] - (int)('1');
				if (board.play(player,row,col)){
					cout << "player " << playerID << " put his piece at " << position << endl;
					break;
				} else {
					cout << "Move not valid! try again" << endl << endl;
				}
			}
		}
		board.printBoard();
		player = -player;
	}
	return 0;
}
