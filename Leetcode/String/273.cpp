/*Integer To English Words
 *Accepted
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string intToString(int num) {
    string belowTen[10] {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string tenToNinteen[10] {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string belowHundred[10] {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string result;
    if (num >= 100) {
        result = belowTen[num / 100] + " Hundred";
        if(num % 100 != 0) result = result + " " + intToString(num % 100);
    }
    else if (num >= 10 && num <= 19) {
        result = tenToNinteen[num - 10];
    }
    else if (num >= 20)
    {
        result = belowHundred[num / 10];
        if (num % 10 != 0) result = result + " " + belowTen[num % 10];
    }
    else result = belowTen[num % 10];
    return result;
}

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string unit[4] {"", "Thousand", "Million", "Billion"};
    vector<int> split;
    while (num != 0) {
        split.push_back(num % 1000);
        num = num / 1000;
    }
    string result = intToString(split[0]);
    for (int i = 1; i < int(split.size()); i++) {
        if (split[i] != 0) {
            string temp = intToString(split[i]) + " " + unit[i];
            if (result != "") result = temp + " " + result;
            else result = temp;
        }
    }
    return result;
}

int main() {
    vector<int> arr{1, 3, 2, 4, 5, 6, 5, 6};
    cout << numberToWords(1234567) << endl;
}

