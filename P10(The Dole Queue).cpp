#include <stdio.h>
#include <ctime> 
#include <iostream>
#include <string>

#define IN "P10IN.txt"
#define OUT "P10OUT.txt"

//副程式:迴轉點名
//idx : 官員當前點到的人的標籤
//step :順/逆著編號點名
//cnt :每回合點擠人
//n :最初的人數
//lab :人員身上的標籤
void rollcall(int& idx, int step, int cnt, int n, int* lab){
    for (int i = 0; i < cnt; i++) {
        //利用do while 迴圈來跳過已經離開的人員
        do {
            idx = idx + step;
            if (idx > n ) {
                idx = 1;   //防止上溢位(overflow)
            }
            if (idx < 1) {
                idx = n;   //防止下溢位(underflow)
            }
        } while (lab[idx] == 0 );
    }
    return;
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int n, k, m;
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n) {
        //人員標籤初始化
        int* lab = new int[n];
        for (int i = 0; i < (n + 1); i++) {
            lab[i] = i;
        }
        int here = n;      //還在場的人員數量
        int ia = n , ib = 1;     // 官員現在點到的人
        while (here) {
            //點名
            rollcall(ia, 1, k, n, &lab[0]);   //官員A點名
            rollcall(ib, -1, m, n, &lab[0]);   //官員B點名
            // 印出被A點到離隊的人員
            printf("%3d", ia);
            here--;
            lab[ia] = 0;
            // 檢查和印出被bbb點到離隊的人員
            if (ia != ib) {
                printf("%3d", ib);
                here--;
                lab[ib] = 0;
            }
            if (here) {
                printf(",");
            }
        }
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
