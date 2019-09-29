static void islandArea(int *area, int **grid, const int rowSize, const int colSize, const int i, const int j)
{
	assert(area);

	if (i < 0 || i > rowSize - 1) {
		return;
	}

	if (j < 0 || j > colSize - 1) {
		return;
	}

	if (grid[i][j] != 1) {
		return;
	}

	// reach here when stepping on a land
	grid[i][j] = -1;
	(*area)++;
	// east
	islandArea(area, grid, rowSize, colSize, i, j + 1);
	// south
	islandArea(area, grid, rowSize, colSize, i + 1, j);
	// north
	islandArea(area, grid, rowSize, colSize, i - 1, j);
	// west
	islandArea(area, grid, rowSize, colSize, i, j - 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int maxArea;

	if (!grid || !*grid || gridSize < 1 || !gridColSize || *gridColSize < 1) {
		return 0;
	}

	maxArea = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			int area = 0;
			islandArea(&area, grid, gridSize, *gridColSize, i, j);
			if (area > maxArea) {
				maxArea = area;
			}
		}
	}

	return maxArea;
}


static int islandArea(int **grid, const int rowSize, const int colSize, const int i, const int j)
{
	int area;
	if (i < 0 || i > rowSize - 1) {
		return 0;
	}

	if (j < 0 || j > colSize - 1) {
		return 0;
	}

	if (grid[i][j] != 1) {
		return 0;
	}

	// reach here when stepping on a land
	grid[i][j] = -1;
	area = 1;
	// east
	area += islandArea(grid, rowSize, colSize, i, j + 1);
	// south
	area += islandArea(grid, rowSize, colSize, i + 1, j);
	// north
	area += islandArea(grid, rowSize, colSize, i - 1, j);
	// west
	area += islandArea(grid, rowSize, colSize, i, j - 1);

	return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
	int maxArea;

	if (!grid || !*grid || gridSize < 1 || !gridColSize || *gridColSize < 1) {
		return 0;
	}

	maxArea = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < *gridColSize; j++) {
			int area = islandArea(grid, gridSize, *gridColSize, i, j);
			if (area > maxArea) {
				maxArea = area;
			}
		}
	}

	return maxArea;
}


/*
 * @lc app=leetcode id=695 lang=c
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (58.79%)
 * Total Accepted:    98.8K
 * Total Submissions: 167.9K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 *
 * Example 1:
 *
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 *
 * Example 2:
 *
 *
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 *
 * Note: The length of each dimension in the given grid does not exceed 50.
 *
 */
