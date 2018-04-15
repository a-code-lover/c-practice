/*Spiral Matrix
 *Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 */
/*something wrong, solution too complicated.
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> result;
	if (matrix.empty()) return result;
	int border[4] = {(int)matrix[0].size() - 1, (int)matrix.size() - 1, 0, 0};
	int flag[4] = {0, 0, 0, 0};
	int i = 0, j = 0, count = 0;
	while(border[0] >= border[2] && border[1] >= border[3]) {
		while (j <= border[0]) {
			cout<<i<<j<<endl;
			result.push_back(matrix.at(i).at(j));
			j++; flag[0] = 1;
		}
		if (flag[0]) {j--; i++; border[3]++; flag[0] = 0;}
		cout<<border[0]<<border[1]<<border[2]<<border[3]<<endl;
		while (i <= border[1]) {
			cout<<i<<j<<endl;
			result.push_back(matrix.at(i).at(j));
			i++; flag[1] = 1;
		}
		if (flag[1]) {i--; j--; border[0]--; flag[1] = 0;}
		cout<<border[0]<<border[1]<<border[2]<<border[3]<<endl;
		while (j >= border[2]) {
			cout<<i<<j<<endl;
			cout<<"hhhl"<<endl;
			result.push_back(matrix.at(i).at(j));
			j--; flag[2] = 1;		
		}
		if (flag[2]) {j++; i--; border[1]--; flag[2] = 0;}
		cout<<border[0]<<border[1]<<border[2]<<border[3]<<endl;
		while (i >= border[3]) {
			cout<<i<<j<<endl;
			result.push_back(matrix.at(i).at(j));
			i--; flag[3] = 1;			
		}
		if (flag[3]) {i++; j++; border[2]++; flag[3] = 0;}
		cout<<border[0]<<border[1]<<border[2]<<border[3]<<endl;
	}
	return result;
}

int main() {
	vector<vector<int>> nums{{1,2,3}, {4,5,6}, {7,8,9}};
	vector<int> result = spiralOrder(nums);
	for (auto item : result) cout<<item<<' ';
	return 1;
}

