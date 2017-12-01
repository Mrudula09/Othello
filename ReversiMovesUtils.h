/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/
ReversiMove *createMove(int x, int y) {
	ReversiMove *move = (struct ReversiMove*)malloc(sizeof(ReversiMove));
	move->x = x-1;
	move->y = y-1;
	return move;
}

/*
Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/
int isvalidCoordinate(ReversiGame*, int, int);
int isValidMove(ReversiGame*, ReversiMove*);

ReversiMove *inputMove(ReversiGame *game) {
	int x, y;
	ReversiMove *move;
	checkReversiGameOver(game);
	do
	{
		printf("enter a move");
		scanf("%d%d", &x, &y);
		move = createMove(x, y);
	} while (isvalidCoordinate(game, x-1, y-1) == 0 || isValidMove(game, move) == 0);
	return move;
}


/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if (x < game->rows && y < game->cols && x >= 0 && y >= 0)
		return 1;
	return 0;
}

/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/

int north(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		--x;
		while (x>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
			--x;
		}
	}
	else
	{
		--x;
		while (x>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			else if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
			--x;
		}
	}
	return 0;
}
int south(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		while (++x && x < game->rows)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
		}
	}
	else
	{
		while (++x && x < game->rows)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
		}
	}
	return 0;
}
int east(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		while (++y && y < game->cols)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
		}
	}
	else
	{
		while (++y && y < game->cols)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
		}
	}
	return 0;
}
int west(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		--y;
		while (y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
			--y;
		}
	}
	else
	{
		--y;
		while (y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			else if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			--y;
		}
	}
	return 0;
}
int northEast(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		--x;
		while (++y && y < game->cols && x>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			else if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			--x;
		}
		return 0;
	}
	else
	{
		--x;
		while (++y && y < game->cols && x>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			else if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			--x;
		}
	}
	return 0;
}
int southWest(ReversiGame *game, int x, int y)
{

	int count = 0;
	if (game->turn == 1)
	{
		--y;
		while (++x && x < game->rows && y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
			--y;
		}
	}
	else
	{
		--y;
		while (++x && x < game->rows && y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
			--y;
		}
	}
	return 0;
}
int northWest(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		--x;
		--y;
		while (x>=0 && y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
			--x;
			--y;
		}
	}
	else
	{
		--x;
		--y;
		while (x>=0 && y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
			--x;
			--y;
		}
	}
	return 0;
}
int southEast(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		while (++x && ++y && x < game->rows && y < game->cols)
		{
			if ((game->board)[x][y] == 'b')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'w')
			{
				return 1;
			}
		}
	}
	else
	{
		while (++x && ++y && x < game->rows && y < game->cols)
		{
			if ((game->board)[x][y] == 'w')
			{
				count++;
			}
			if (count >= 1 && (game->board)[x][y] == 'b')
			{
				return 1;
			}
		}
	}
	return 0;
}
int isValidMove(ReversiGame *game, ReversiMove *move) {
	int flag = 0;
	if (isvalidCoordinate(game, move->x, move->y) == 0)
		return 0;
	if ((game->board)[move->x][move->y] == 'b')
		return 0;
	if ((game->board)[move->x][move->y] == 'w')
		return 0;
	if (north(game, move->x, move->y) == 1)
		return 1;
	if (south(game, move->x, move->y) == 1)
		return 1;
	if (east(game, move->x, move->y) == 1)
		return 1;
	if (west(game, move->x, move->y) == 1)
		return 1;
	if (northEast(game, move->x, move->y) == 1)
		return 1;
	if (southWest(game, move->x, move->y) == 1)
		return 1;
	if (northWest(game, move->x, move->y) == 1)
		return 1;
	if (southEast(game, move->x, move->y) == 1)
		return 1;
	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/
int move(ReversiGame *game)
{
	int c = 0;
	int i, j;
	c++;
	ReversiMove *move;
	for (i = 1; i <= game->rows; i++)
	{
		for (j = 1; j <= game->cols; j++)
		{
			move = createMove(i, j);
			if (isValidMove(game, move) == 1)
				return 1;
		}
	}
	return 0;
}
int hasMove(ReversiGame *game){
	if (game->turn == 1)
	{
		if (move(game) == 0)
		{
			game->turn = -1;
			/*{
				if (move(game) == 0)
				{

					return 0;
				}
				else
				{
					return 1;//changed 0 to 1
				}
			}*/
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		if (move(game) == 0)
		{
			game->turn = 1;
			/*{
				if (move(game) == 0)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}*/
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	(game->NumberofMoves)++;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	if (game->turn == -1)
		game->turn = 1;
	else
		game->turn = -1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	game->state = 1;
		if (game->blackCount > game->whiteCount)
		{
			game->winner = -1;
		}
		else if (game->blackCount < game->whiteCount)
		{
			game->winner = 1;
		}
		else
		{
			game->winner = 0;
		}
	return;
}

/*
Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
This function performs move action on the board
Note : call validity check performs using above functions before making a move
returns :
true on move sucess
false if move is invalid
*/
void northMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		--x;
		while (x>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
			--x;
		}
	}
	else
	{
		--x;
		while (x>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
			--x;
		}
	}
	return;
}
void southMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		while (++x && x < game->rows)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		while (++x && x < game->rows)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
		}
	}
	return;
}
void eastMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		while (++y && y < game->cols)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->whiteCount++;
				game->blackCount--;
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		while (++y && y < game->cols)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
		}
	}
	return;
}
void westMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		--y;
		while (y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->whiteCount++;
				game->blackCount--;
			}
			else
			{
				return;
			}
			--y;
		}
	}
	else
	{
		--y;
		while (y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
			--y;
		}
	}
	return;
}
void northEastMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		--x;
		while (++y && y < game->cols && x>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
			--x;
		}
	}
	else
	{
		--x;
		while (++y && y < game->cols && x>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
			--x;
		}
	}
	return;
}
void southWestMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		--y;
		while (++x && x < game->rows && y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
			--y;
		}
	}
	else
	{
		--y;
		while (++x && x < game->rows && y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
			--y;
		}
	}
	return;
}
void northWestMove(ReversiGame *game, int x, int y)
{
	if (game->turn == 1)
	{
		--x;
		--y;
		while (x>=0 && y>=0)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
			--x;
			--y;
		}
	}
	else
	{
		--x;
		--y;
		while (x>=0 && y>=0)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
			--x;
			--y;
		}
	}
	return;
}
void southEastMove(ReversiGame *game, int x, int y)
{
	int count = 0;
	if (game->turn == 1)
	{
		while (++x && ++y && x < game->rows && y < game->cols)
		{
			if ((game->board)[x][y] == 'b')
			{
				(game->board)[x][y] = 'w';
				game->blackCount--;
				game->whiteCount++;
			}
			else
			{
				return;
			}
		}
	}
	else
	{
		while (++x && ++y && x < game->rows && y < game->cols)
		{
			if ((game->board)[x][y] == 'w')
			{
				(game->board)[x][y] = 'b';
				game->blackCount++;
				game->whiteCount--;
			}
			else
			{
				return;
			}
		}
	}
	return;
}
bool playMove(ReversiGame *game, ReversiMove *move) {
	hasMove(game);
	if (isvalidCoordinate(game, move->x, move->y) == 1)
	{
		if (isValidMove(game, move) == 1)
		{
			if (game->turn == 1)
			{
				(game->board)[move->x][move->y] = 'w';
				game->whiteCount++;
			}
			else
			{
				(game->board)[move->x][move->y] = 'b';
				game->blackCount++;
			}
			if (north(game, move->x, move->y))
			{
				northMove(game, move->x, move->y);
			}
			if (south(game, move->x, move->y))
			{
				southMove(game, move->x, move->y);
			}
			if (east(game, move->x, move->y))
			{
				eastMove(game, move->x, move->y);
			}
			if (west(game, move->x, move->y))
			{
				westMove(game, move->x, move->y);
			}
			if (northEast(game, move->x, move->y))
			{
				northEastMove(game, move->x, move->y);
			}
			if (southEast(game, move->x, move->y))
			{
				southEastMove(game, move->x, move->y);
			}
			if (northWest(game, move->x, move->y))
			{
				northWestMove(game, move->x, move->y);
			}
			if (southWest(game, move->x, move->y))
			{
				southWestMove(game, move->x, move->y);
			}
		}
		else
		{
			return false;
		}
		modify(game);
		checkReversiGameOver(game);
		return true;
	}
	return false;
}



void printWinner(ReversiGame *game) {
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
	if (game->winner == 1)
	{
		printf("%s has won.", game->player1name);
	}
	else if (game->winner == -1)
	{
		printf("%s has won.", game->player2name);
	}
	else
	{
		printf("Game is Drawn");
	}
}
