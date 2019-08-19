void updateDist(int **rooms, int rowSize, int colSize, int i, int j, int distToGate)
{
	if (i < 0 || i > rowSize - 1) {
		return;
	}

	if (j < 0 || j > colSize - 1) {
		return;
	}

	// we hit a wall
	if (rooms[i][j] == -1) {
		return;
	}

	// we step onto another gate
	if (rooms[i][j] == 0 && distToGate > 0) {
		return;
	}

	if (distToGate < rooms[i][j] || distToGate == 0) {
		rooms[i][j] = distToGate;

		distToGate++;
		// East
		updateDist(rooms, rowSize, colSize, i, j + 1, distToGate);
		// South
		updateDist(rooms, rowSize, colSize, i + 1, j, distToGate);
		// North
		updateDist(rooms, rowSize, colSize, i - 1, j, distToGate);
		// West
		updateDist(rooms, rowSize, colSize, i, j - 1, distToGate);
	}
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
	int i, j;
	if (!rooms || !*rooms || roomsSize < 1 || !roomsColSize || *roomsColSize < 1) {
		return;
	}

	for (i = 0; i < roomsSize; i++)
		for (j = 0; j < *roomsColSize; j++) {
			if (rooms[i][j] == 0) {
				updateDist(rooms, roomsSize, *roomsColSize, i, j, 0);
			}
		}
}

/*
 * Given the 2D grid:
 *
 * INF  -1  0  INF
 * INF INF INF  -1
 * INF  -1 INF  -1
 *   0  -1 INF INF
 *
 * After running your function, the 2D grid should be:
 *
 * 3  -1   0   1
 * 2   2   1  -1
 * 1  -1   2  -1
 * 0  -1   3   4
*/
