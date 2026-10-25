#define SIZE 8

//Part a : 
typedef enum {
	PAWN,
	KNIGHT,
	BISHOP, 
	ROOK, 
	QUEEN,
	KING, 
	EMPTY,
} Piece;

typedef enum {
	BLACK, 
	WHITE
} Color;

//Part b : 
typedef struct {
	Piece piece;
	Color color;
} Square;

//Part c : 
Square board[SIZE][SIZE];

//Part d : 
void Initializer() {
	//2 upper row = BLACK
	int row = 0; 
	board[row][0].piece = board[row][SIZE-1].piece = ROOK;
	board[row][1].piece = board[row][SIZE-2].piece = KNIGHT;
	board[row][2].piece = board[row][SIZE-3].piece = BISHOP;
	board[row][3].piece = QUEEN; board[row][4].piece = KING;
	
	row = 1; 
	for(int i = 0; i<SIZE; i++) board[row][i].piece = PAWN;

	for(int i = 0; i<2; i++) {
		for(int j = 0; j < SIZE; j++) board[i][j].color = BLACK;
	}

	//2 lower row = WHITE
	row = SIZE - 1; 
	board[row][0].piece = board[row][SIZE-1].piece = ROOK;
	board[row][1].piece = board[row][SIZE-2].piece = KNIGHT;
	board[row][2].piece = board[row][SIZE-3].piece = BISHOP;
	board[row][3].piece = QUEEN; board[row][4].piece = KING;

	row = SIZE - 2; for(int i = 0; i<SIZE; i++) board[row][i].piece = PAWN;
	for(int i = SIZE-2; i<SIZE; i++) {
		for(int j = 0; j < SIZE; j++) board[i][j].color = WHITE;
	}

	//The rest is empty : 
	for(int i = 2; i < SIZE - 2; i++) {
		for (int j = 0; j < SIZE; j++) board[i][j].piece = EMPTY;
	}
}