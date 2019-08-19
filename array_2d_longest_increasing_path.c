static int increasingPathLength(int **matrix, const int rowSize, const int colSize, int row, int column, const int prevVal, int **longestIncPathLenFromElement)
{
	int maxLen, len;

	if (row < 0 || row > rowSize - 1) {
		return 0;
	}

	if (column < 0 || column > colSize - 1) {
		return 0;
	}

	if (matrix[row][column] <= prevVal) {
		return 0;
	}

	if (longestIncPathLenFromElement[row][column] > 0) {
		return longestIncPathLenFromElement[row][column];
	}

	// reach here when prevVal < matrix[row][column]
	maxLen = 0;
	// east
	len = increasingPathLength(matrix, rowSize, colSize, row, column + 1, matrix[row][column], longestIncPathLenFromElement);
	if (len > maxLen) {
		maxLen = len;
	}
	// south
	len = increasingPathLength(matrix, rowSize, colSize, row + 1, column, matrix[row][column], longestIncPathLenFromElement);
	if (len > maxLen) {
		maxLen = len;
	}
	// west
	len = increasingPathLength(matrix, rowSize, colSize, row, column - 1, matrix[row][column], longestIncPathLenFromElement);
	if (len > maxLen) {
		maxLen = len;
	}
	// north
	len = increasingPathLength(matrix, rowSize, colSize, row - 1, column, matrix[row][column], longestIncPathLenFromElement);
	if (len > maxLen) {
		maxLen = len;
	}
	maxLen++;
	longestIncPathLenFromElement[row][column] = maxLen;

	return maxLen;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
	int i, j;
	int maxLen;

	if (!matrix || !*matrix || matrixSize < 1 || !matrixColSize || *matrixColSize < 1) {
		return 0;
	}

	int **longestIncPathLenFromElement = (int **)malloc(matrixSize * sizeof(int *));
	for (i = 0; i < matrixSize; i++) {
		longestIncPathLenFromElement[i] = (int *)malloc(*matrixColSize * sizeof(int));
		for (j = 0; j < *matrixColSize; j++) {
			longestIncPathLenFromElement[i][j] = 0;
		}
	}

	maxLen = 0;
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < *matrixColSize; j++) {
			int len = increasingPathLength(matrix, matrixSize, *matrixColSize, i, j, matrix[i][j] - 1, longestIncPathLenFromElement);
			if (len > maxLen) {
				maxLen = len;
			}
		}
	}
	return maxLen;
}

/*
 * Example 1:
 *
 * Input: nums =
 * [
 *   [9,9,4],
 *   [6,6,8],
 *   [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 * Example 2:
 *
 * Input: nums =
 * [
 *   [3,4,5],
 *   [3,2,6],
 *   [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 */
