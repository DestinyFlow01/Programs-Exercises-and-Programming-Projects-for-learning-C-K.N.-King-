typedef enum {
	NORTH, 
	SOUTH,
	EAST, 
	WEST
} Direction;

int x, y;
Direction direction; 
switch(direction) {
	case NORTH : y--; break;
	case SOUTH : y++; break;
	case EAST : x++; break;
	case WEST : x--; break;
}