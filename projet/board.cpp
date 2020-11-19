#include "board.h"
#include <iostream>

Board::Board(){
	matrix[3][3] = -1;
	matrix[3][4] = 1;
	matrix[4][3] = 1;
	matrix[4][4] = -1;
}

void Board::printBoard(){
	std::cout << "\n  a b c d e f g h  \n";
	for (int i = 0; i < 8; i++) {
		std::cout << i+1 << " ";
		for (int j = 0; j < 8; j++) {
			if (matrix[i][j] == 1) {
				std::cout << "X ";
			} else if (matrix[i][j] == -1) {
				std::cout << "O ";
			} else {
				std::cout << ". ";
			}
		}
		std::cout << i+1 << "\n";
	}
	std::cout << "  a b c d e f g h  \n\n";
}

bool Board::play(int player, int row, int col){
	bool MoveIsValid = false;
	if (matrix[row][col] == 0) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int k = 1;
				while ( col+k*i >= 0 && col+k*i <= 7 && row+k*j >= 0 && row+k*j <= 7 && !(i==0 && j==0)) {
					// tant que les indices restent bien dans les limites du tableau, et que i et j ne sont pas nuls en même temps
					if (matrix[row+k*j][col+k*i] == -player) {
						k++;
					} else if (matrix[row+k*j][col+k*i] == player && k>1) {
						for (int l = k-1; l >= 0; l--) {
								matrix[row+l*j][col+l*i] = player;
						}
						MoveIsValid = true;
						break;
					} else {
						break;
					}
				}
			}
		}
	}
	return MoveIsValid;
}

bool Board::isValidMove(int player, int row, int col){
	if (matrix[row][col] == 0) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int k = 1;
				while ( col+k*i >= 0 && col+k*i <= 7 && row+k*j >= 0 && row+k*j <= 7 && !(i==0 && j==0)) {
					// tant que les indices restent bien dans les limites du tableau, et que i et j ne sont pas nuls en même temps
					if (matrix[row+k*j][col+k*i] == -player) {
						k++;
					} else if (matrix[row+k*j][col+k*i] == player && k>1) {
						return true;
					} else {
						break;
					}
				}
			}
		}
	}
	return false;
}

bool Board::isGameOver(){
	if (validMoveExists(1) || validMoveExists(-1)) {
		return false;
	}
	printScore();
	return true;
}

bool Board::validMoveExists(int player){
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			if (isValidMove(player,i,j)) {
				return true;
			}
		}
	}
	return false;
}

void Board::printScore(){
	int scoreP1 = 0;
	int scoreP2 = 0;
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			if (matrix[i][j] == 1){
				scoreP1++;
			} else if (matrix[i][j] == -1) {
				scoreP2++;
			}
		}
	}
	std::cout << "GAME OVER\n" << "score is :\n" << "P1 : " << scoreP1 << "\nP2 : " << scoreP2 << std::endl;
}
