#include <stdio.h>
#include <string>
#include <iostream>
#include <ctime>


#define IN "P11IN.txt"
#define OUT "P11OUT.txt"

using namespace std;

//製作解碼查詢表
int T[8][128];
bool mkT() {
    //查詢表前置處理
    memset(T, 0, sizeof(T));           //矩陣變數初始化(歸零)
    string str;
    while (getline(cin, str) && str.empty());  //跳過讀取空字串
    if (cin.eof() || cin.fail()) {      //讀取到結尾或失敗時回傳false 
        return false;
    }
    //製作查詢表
    int c = 0;  //讀取str字串的索引
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < (1 << i) -1 ; j++) {
            T[i][j] = str[c];
            c++;
            if (c > str.size()) {
                return true;
            }
        }
    }
}

// 5(10) -> 101(2)
// 5(10) << 1 -> 101(2) << 1 ->  1010(2) -> 10(10)

//二進制 轉 十進制
int bin2dec(int leng) {
    int dec = 0; 
    char c; 
    for (int i = 0; i < leng;i++) {
        //=_= =_= =_= =_= =_= =_= =_= =_=
        while ((c = getchar()) == '\n');  // 用while 迴圈跳過讀取到換行字元'\n'
        dec = dec * 2 + c - '0';
    }
    return dec;
}
//

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    while (mkT()) {
        int leng;
        char c;
        while ((leng = bin2dec(3)) != 0) {   //解碼讀取長度(長度為0時結束程式)
            int idx;
            //解碼索引(讀到全部都 1 重新解碼長度)
            while ((idx = bin2dec(leng)) != (1 << leng) - 1) {   
                c = T[leng][idx];  //int 轉換為 char
                cout << c;
            }
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
