#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>


#define IN "P14IN.txt"
#define OUT "P14OUT.txt"

using namespace std;

vector<int> v[25];    //宣告儲存的矩陣變數(全域)

//副程式 : 找尋木塊位置 p 和高度 h
//b要找尋位置的木塊
void find_block(int b, int n, int& p, int& h) {
    for (p = 0; p < n; p++) {
        for (h = 0; h < v[p].size(); h++) {
            if (v[p][h] == b) {
                return ;
            }
        }
    }
}

// 副程式 : 清除木塊上方的其他木塊
void clear_above(int p, int h) {
    for (int i = v[p].size() - 1; i > h; i--) {
        int b = v[p][i];
        v[b].push_back(b);
    }
    v[p].resize(h + 1);
}

//副程式: 將p1 指定木塊以上的木塊移到p2
void pile_over(int p1, int h, int p2) {
    for (int i = h; i < v[p1].size(); i++) {
        v[p2].push_back(v[p1][i]);
    }
    v[p1].resize(h);
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int n; 
    cin >> n;                         // 讀木塊數量
    for (int i = 0; i < n; i++ ) {
        v[i].push_back(i);            // 木塊初始化
    }
    //讀取命令
    string s1, s2;       //讀命令字串 s1; move & pile s2; onto & over
    int A, B;            //讀命令木塊編號
    int pA, pB, hA, hB;  //P位置 H高度
    while (cin >> s1 && s1 != "quit") {
        cin >> A >> s2 >> B;
        //找 A B 木塊的位置和高度
        find_block(A, n, pA, hA);
        find_block(B, n, pB, hB);
        if (pA != pB) {            //pA == pB ;非法命令，所以pA != pB才會繼續
            // 清空木塊上方其他木塊的狀況
            if (s1 == "move") {
                clear_above(pA, hA);
            }
            if (s2 == "onto") {
                clear_above(pB, hB);
            }
            //木塊移動
            pile_over(pA, hA, pB);

        }
    }

    //印出結果
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }


    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
