/*Max Area of Island
 *Given a non-empty 2D array grid of 0's and 1's, 
 *an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
 *Accepted
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {	
	visited[i][j] = 1;
	int m = grid.size(), n = grid[0].size();
	int direction[4] = {0};
	if (grid[i][j] == 0) return 0;
	else {
		//at the beginning i miss the visited condition and get runnnig error
		if ((i - 1) >= 0 && !visited[i - 1][j]) direction[0] = dfs(grid, i - 1, j, visited);
		if ((j - 1) >= 0 && !visited[i][j - 1]) direction[1] = dfs(grid, i, j - 1, visited);
		if ((i + 1) < m && !visited[i + 1][j]) direction[2] = dfs(grid, i + 1, j, visited);
		if ((j + 1) < n && !visited[i][j + 1]) direction[3] = dfs(grid, i, j + 1, visited);
		//cout<<"push"<<endl;
		return direction[0] + direction[1] + direction[2] + direction[3] + 1;
	}
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
	//consider empty separately
	if(grid.empty()) return 0;
	int m = grid.size(), n = grid[0].size();
	int maxArea = 0;
	vector<vector<int>> visited(m, vector<int> (n, 0));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			//cout<<i<<j<<endl;
			if (!visited[i][j]) maxArea =max(maxArea, dfs(grid, i, j, visited));
		}
	return maxArea;
}

int main() {
	vector <vector<int>> matrix{
	};
	cout<<maxAreaOfIsland(matrix)<<endl;
	return 1;

}
