#include <stdio.h>
#include <ctime> 
#include <iostream>
#include <string>

#define IN "P09IN.txt"
#define OUT "P09OUT.txt"

using namespace std;

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int game;
    while (cin >> game && game != -1) {
        // 讀取電腦題目跟玩家猜測
        string s, g;
        cin >> s >> g;
        //印出局數
        cout << "Round " << game << endl; 
        //遊戲規則處理
        int wrong = 0;      //記錄猜錯次數 ; 敗北條件
        int victory = 0;    //記錄猜對次數 ; 勝利條件
        for (int i = 0; i < g.size();i++) {
            bool nohit = true;     // 判斷有無猜到字元
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == g[i]) {
                    nohit = false; 
                    victory++;
                    s[j] = '\0';
                }
            }
            //回合結算
            //判斷有無猜到
            if (nohit == true) {
                wrong++;
            }
            //敗北判斷
            if (wrong == 7) {
                cout << "You lose." << endl; 
                break;
            }
            //勝利判斷
            if (victory == s.size()) {
                cout << "You win." << endl;
                break;
            }
        }
        //和局判斷
        if (wrong < 7 && victory < s.size()) {
            cout << "You chicked out." << endl;
        }
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
