#include <stdio.h>    
#include <string>     
#include <iostream>   
#include <ctime>
#include <algorithm>  //演算法工具;



#define IN "P20IN.txt"
#define OUT "P20OUT.txt"

using namespace std;

//副程式：印出ls命令
void printls(string s, int len = 60, char ex = '-') {
    cout << s;
    for (int i = 0; i < len - s.size(); i++) {
        cout << ex;      //印出補充字元ex 
    }
    return; 
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int F;            //讀檔案數量
    string fn[100];   //儲存檔案名稱的變數
    int R, C, idx;    //列印用索引變數

    while (cin >> F) {
        //找最長的檔案名稱
        int M = 0;    //M最長的檔案名稱
        for (int i = 0; i < F; i++) {
            cin >> fn[i];
            M = max(M, (int)fn[i].size());
        }
        //計算位置索引
        C = (60 - M) / (M + 2) + 1;
        R = (int)ceil((double)F / C);
        printls("");    //印出分隔線
        printf("\n");
        sort(fn, fn + F);   //檔案名稱1~9 A~Z排序
        //印出ls 命令結果
        for (int r = 0; r < R;r++) {
            for (int c = 0; c < C; c++) {
                idx = c * R + r;
                if (idx < F) {
                    printls(fn[idx], c == C - 1 ? M : M + 2, ' ');
                }
            }
            cout << endl; 
        }
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
