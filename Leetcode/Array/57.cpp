/*Insert Interval
 *Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *You may assume that the intervals were initially sorted according to their start times.
 *Accepted.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        Interval first(INT_MIN, INT_MIN), last(INT_MAX, INT_MAX);
        intervals.insert(intervals.begin(), first);
        intervals.push_back(last);
        for (auto item : intervals) cout << "<" << item.start << "," << item.end << ">" << " ";
        cout << endl;
        int size = intervals.size();
        int leftStart, leftEnd, rightStart, rightEnd;
        int erase[2];
        for (int i = 0; i + 1 < size; ++i) {
            if (newInterval.start >= intervals.at(i).start && newInterval.start <= intervals.at(i + 1).start) {
                leftStart = i; leftEnd = i + 1;
                if (newInterval.start <= intervals.at(leftStart).end) {
                    erase[0] = leftStart;
                    newInterval.start = intervals.at(leftStart).start;
                }
                else {
                    erase[0] = leftEnd;
                }
            }
            if (newInterval.end >= intervals.at(i).end && newInterval.end <= intervals.at(i + 1).end) {
                rightStart = i; rightEnd = i + 1;
                if (newInterval.end >= intervals.at(rightEnd).start) {
                    erase[1] = rightEnd;
                    newInterval.end = intervals.at(rightEnd).end;
                }
                else {
                    erase[1] = rightStart;
                }
            }
        }
        cout << erase[0] << erase[1] << endl;
        intervals.erase(intervals.begin() + erase[0], intervals.begin() + erase[1] + 1);
        for (auto item : intervals) cout << "<" << item.start << "," << item.end << ">" << " ";
        cout << endl;
        intervals.insert(intervals.begin() + erase[0], newInterval);
        intervals.erase(intervals.begin());
        intervals.pop_back();
        return intervals;
    }
};

int main() {
    std::vector<Interval> intervals;
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(12, 16));
    Interval newInterval(4, 9);
    Solution s;
    vector<Interval> result = s.insert(intervals, newInterval);
    for (auto item : result) cout << "<" << item.start << "," << item.end << ">" << " ";
}