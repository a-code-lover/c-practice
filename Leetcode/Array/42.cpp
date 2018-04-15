/*Trapping Rain Water
 *Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 *compute how much water it is able to trap after raining.
 */
/*Wrong Answer
 *Although finding all the peaks, hard to consider all conditions using peaks.
 *Idea:maintain a maxLeft and a maxRight as borders of a container, fill it from the shorter side to 
 *the higher side, and update borders. call it two pointers?
 *More concise: https://leetcode.com/problems/trapping-rain-water/discuss/17364/7-lines-C-C++
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int first = INT_MIN, last = INT_MIN, sum = 0;
        height.insert(height.begin(), first);
        height.push_back(last);
        vector <int> peak = findPeak(height);
        for (auto item : peak) cout<<item<<' ';
        cout << endl;
        int sizePeak = peak.size();
        for (int i = 0; i < sizePeak - 2; i += 2) {
            int top = min(height.at(peak.at(i)), height.at(peak.at(i + 2)));
            for (int j = peak.at(i) + 1; j < peak.at(i + 2); ++j) {
                if (height.at(j) < top) sum += top - height.at(j);
            }
        }
        return sum;
    }

private:
    vector <int> findPeak(vector<int>& height) {
        int size = height.size();
        for (auto item : height) cout<<item<<' ';
        cout << size <<endl;
        vector <int> peak;
        for (int i = 1; i < size - 1;) {
            if (height.at(i) > height.at(i - 1)) {               
                i++;
                cout<<"max"<<i<<endl;
                while (height.at(i) == height.at(i - 1) && i < size - 1) {
                    i++;
                }
                if (height.at(i) < height.at(i - 1)) {
                    peak.push_back(i - 1);
                    continue;
                }
                else continue;
            }
            if (height.at(i) < height.at(i - 1)) {               
                i++;
                cout<<"min"<<i<<endl;
                while (height.at(i) == height.at(i - 1) && i < size - 1) {
                    i++;
                }
                if (height.at(i) > height.at(i - 1)) {
                    peak.push_back(i - 1);
                    continue;
                }
                else continue;
            }
        }
        return peak;
    }
};

int main() {
    vector <int> height{5,2,1,2,1,5};
    Solution s;
    cout << s.trap(height) << endl;
}