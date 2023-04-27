#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


#define IN "P13IN.txt"
#define OUT "P13OUT.txt"

using namespace std;

#define ALL(x) x.begin(), x.end()


int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int N, Q;    //N個大理石和Q個問題
    int CASE = 0; 
    int mb;

    while (cin >> N >> Q && N != 0) {
        vector<int> mbs(N);
        //用變數宣告矩陣;vector<int> mbs(N);
        //用常數宣告矩陣;vector<int> mbs[5];
        for (int i = 0; i < N; i++) 
            cin >> mbs[i];//讀取文件; 大理石的數字
        sort(ALL(mbs));    //把大理石從小到大排序
        
        cout << "CASE #" << ++CASE << ":" << endl;  //印出第幾個case
        for (int q = 0;q < Q; q++) {
            cin >> mb;
            //找出問題大理石的位置
            int pos = lower_bound(ALL(mbs), mb) - mbs.begin();   
            //印出大理石的位置
            if (pos < mbs.size() && mbs[pos] == mb)
                cout << mb << " found at " << (pos + 1) << endl;
            else
                cout << mb << " not found. " << endl;
        }
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
