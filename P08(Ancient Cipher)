#include <stdio.h>
#include <ctime>
#include <iostream>
#include <string>
#include <algorithm>


#define IN "P08IN.txt"
#define OUT "P08OUT.txt"

using namespace std;

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    string str1, str2;
    bool flag = true; 
    while (cin >> str1 >> str2 && flag) {
        //讀取檢查
        if (!cin.eof() && cin.fail()) {
            flag = false;
            continue;
        }
        //紀錄字母出現次數
        int code1[26] = { 0 }, code2[26] = { 0 };
        for (int i = 0; i < str1.size(); i++) {
            code1[str1[i] - 'A']++;
            code2[str2[i] - 'A']++;
        }
        //出現次數重新排列
        sort(code1, code1 + 25);
        sort(code2, code2 + 25);

        // 比對重新排列的出現次數
        bool ans = true;
        for (int i = 0; i < 26; i++) {
            if (code1[i] != code2[i]) {
                ans = false; 
                i = 26;        // break 
            }
        }
        string output = ans ? "YES" : "NO";
        cout << output << endl;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
