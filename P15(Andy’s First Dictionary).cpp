#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

#include <set>         //集合容器工具 : 自動A~Z排序
#include <cctype>      //字元處理工具


#define IN "P15IN.txt"
#define OUT "P15OUT.txt"

using namespace std;


int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    string s;
    set <string> dict;

    //讀輸入  並把 英文字母縮成小寫
    
    while (cin >> s) {
        string s2;
        for (char c : s) {
            if (isalpha(c)) {
                s2 += tolower(c);   
                //isalpha(x) 檢查字元是否為英文字母    
                // s2 = s2 + string (1, tolower(c));
            }
            
        }
        dict.insert(s2);
    }
    for (string t : dict) {
        cout << t << endl;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
