#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>     //矩陣容器工具
#include <ctime>
#include <algorithm>  
#include <map>        //表格容器工具

#define IN "P16IN.txt"
#define OUT "P16OUT.txt"

using namespace std;

#define ALL(x) x.begin(), x.end()

//副程式 : 字串正規化
string sNorm(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);     //字母變小寫
    }
    sort(ALL(s));    // 字母A~Z排序
    return s;
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    string s, sn;     //s 讀取的字串  sn字串正規化後的儲存變數
    //words 紀錄輸入檔的單字   ans 要印出反片語單字
    vector <string> words, ans;
    map<string, int> cnt;    // cnt 表格; 紀錄(正規化)字串出現的次數
    //紀錄原始單字
    while (cin >> s && s != "#") {
        words.push_back(s);  // 儲存原單字
        sn = sNorm(s);       // 單字字串正規化
        //檢查正規化單字是否出現過
        if (!cnt.count(sn)) cnt[sn] = 0;    //沒出現過    新增位置給正規化字串
        cnt[sn]   ++;
    }
    //找出反片語
    for (int i= 0; i < words.size(); i ++ ){
        sn = sNorm(words[i]);   //正規化儲存的單字
        // 如果正規化字串只出現一次，將該單字存成反片語
        if (cnt[sn] == 1)  ans.push_back(words[i]);
    }
    sort(ALL(ans));      //把反片語的單字 A~Z 排序 
    // 印出反片語
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
