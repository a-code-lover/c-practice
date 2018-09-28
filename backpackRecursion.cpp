/*its eaay to use dp and recursion to deal with backpack problem,
 *but no easy to save intermediate results.
 *we use the idea of a binary tree to return the intermediate path.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Result {
    int num;
    vector<int> t;
};

Result result{0, {}};

Result dp(int a[], int n, int w) {
    if (n < 0 ) {
        Result s{0, {}};
        return s;
    }
    if (a[n] > w) {
        Result tmp = dp(a, n - 1, w);
        tmp.t.push_back(0);
        return tmp;
    }
    else {
        //cout<<"a"<<endl;
        Result r1 = dp(a, n - 1, w);
        Result r2 = dp(a, n - 1, w - a[n]);
        if(r2.num + 1 >= r1.num) {
            r2.t.push_back(1);
            r2.num++;
            return r2;
        }
        else {
            r1.t.push_back(0);
            return r1;
        }
    }
}

int main() {
    int a[6] = {2,7,3,4,9,6};
    int w =  7   ;
    Result aaa = dp(a, 5, w);
    cout<< aaa.num<<endl;
    for (auto item : aaa.t)
        cout<<item<<' ';
    return 1;
}

