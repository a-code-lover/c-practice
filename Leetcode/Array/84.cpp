/*Largest Rectangle in Histogram
 *Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 *find the area of largest rectangle in the histogram.
 *Accepted.
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <list>
#include <string> 
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;


class Solution { 
public: 
	Solution(){};
	~Solution(){};
    int largestRectangleArea(vector<int>& heights) {
    	int size = heights.size();
    	int result[size], max = 0;
    	large(heights, result);
    	for (int i = 0; i < size; ++i){
    		if (result[i] > max) max = result[i];
    		cout<<result[i]<<endl;
    	}
    	return max;
    }

private:
    void large(vector<int>& heights, int result[]) {
    	for (int i = 0; i < heights.size(); ++i) {
    		int sum = heights.at(i);
    		int before = i - 1, next = i + 1;
    		while(before >=0 && heights.at(before--) >= heights.at(i)) sum += heights.at(i);
    		while(next < heights.size() && heights.at(next) >= heights.at(i)) {
    			if (heights.at(next) > heights.at(i)) {
    				sum += heights.at(i);
    				next ++;
    			}
    			if (heights.at(next) == heights.at(i)) {
    				sum += heights.at(i);
    				next ++; i++;
    			}
    		}
    		result[i] = sum;
    	}        
    }
};

int main(){
	Solution A;
	int arr[5] = {1,3,4,6,9};
	vector<int> vec(arr, arr+5);
	cout<<A.largestRectangleArea(vec)<<endl;
}