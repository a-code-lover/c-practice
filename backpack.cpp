#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int n = 6; //物品数
    int a[6] = {1, 2, 3, 4, 5, 6}; //物品重量
    int w = 10;  //背包大小
    int dp[11] = {0};  //最多装几个物品
    int idx[11]; 
    for (int i = 0; i < n; i++) {
        for (int m = w; m >= a[i]; m--) {
            if (dp[m] < dp[m - a[i]] + 1) {
                dp[m] = dp[m - a[i]] + 1;
                idx[m] = i;
            }
        }
    }

    cout<<dp[10]<<endl;

    int tmp = w;
    while(tmp > 0) {
        cout<<a[idx[tmp]]<<' ';
        tmp -= a[idx[tmp]];
    }

    return 1;
}

