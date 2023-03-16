#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string>


#define IN "P07IN.txt"
#define OUT "P07OUT.txt"

using namespace std;

bool findLess(string str, int pos1, int pos2) {
    for (int j=0; j < str.size(); j++) {
        //計算要比較的字元位置
        int p1 = (pos1 + j) % str.size();
        int p2 = (pos2 + j) % str.size();
        //發現字元不同時的處理
        if (str[p1] != str[p2])
            return str[p1] < str[p2];
    }
    return false;  //比較字元完全相同的時候
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    //讀取要處理字串數量
    int lines;
    cin >> lines;
    for (int n = 0; n < lines; n++) {
        //讀取題目字串
        string input;
        cin >> input;
        int newHead = 0; // 新的字首
        // 找新環狀序列最小表示新字首
        for (int i = 0; i < input.size();i++) {
            if (findLess(input, i, newHead))
                newHead = i;
        }
        //印出環狀序列最小表示
        for (int i = 0;i < input.size();i++) {
            int oPos = (newHead + i) % input.size();
            cout << input[oPos];
        }
        cout << endl;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
