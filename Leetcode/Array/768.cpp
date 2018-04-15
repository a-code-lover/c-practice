/*Max Chunks to Make Sorted
 *Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), 
 *and individually sort each chunk.  After concatenating them, the result equals the sorted array.
 *Accepted.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> chunk {arr.at(0)};
        vector<vector<int>> result {chunk};
        stack<int> maxInChunk;
        maxInChunk.push(arr.at(0));
        chunk.clear();
        int size = arr.size();
        for (int i = 1; i < size; ++i) {
            int cmax = arr.at(i);
            chunk.push_back(i);
            while (!maxInChunk.empty() && arr.at(i) < maxInChunk.top()) {
                cmax = max(cmax, maxInChunk.top());
                maxInChunk.pop();
                chunk.insert(chunk.begin(), result.back().begin(), result.back().end());
                result.pop_back();
            }
            result.push_back(chunk);
            chunk.clear();
            maxInChunk.push(cmax);
        }
        return result.size();
    }
};

int main() {
    vector<int> arr{1,3,2,4,5,6,5,6};
    Solution s;
    cout<<s.maxChunksToSorted(arr)<<endl;
}