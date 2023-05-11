#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>     //矩陣容器工具
#include <ctime>
#include <algorithm>  //演算法工具 ; 聯集 交集
#include <map>        //表格容器工具 ; 集合 輸出轉換
#include <set>        //集合容器工具
#include <stack>      //堆疊容器工具
#include <iterator>   //迭代器工具 ; 用來編輯集合容器


#define IN "P17IN.txt"
#define OUT "P17OUT.txt"

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

//全域變數
typedef set<int> SET;  //型態定義 ; 把set<int> 改寫成SET
map<SET, int > setCatch; // set 轉id 
vector <SET> idCatch; //id 轉set
//副程式 SET轉int輸出
int ID(SET x) {
    //檢查x集合是否存在
    if (setCatch.count(x))    return setCatch[x];  //如果存在 就把集合x回傳
    //如果不存在 就新增集合x再回傳
    idCatch.push_back(x);
    setCatch[x] = idCatch.size() - 1; 
    return setCatch[x];
}

int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int N, C;     //N次運算 C的命令
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C; 
        stack<int> setID;
        for (int j = 0; j < C; j++) {
            string s; // 讀命令字串 s
            cin >> s; // PUSH , DUP , UNION, INTERSECTION , ADD
            if (s[0] == 'P') {   //push命令
                SET x;
                setID.push(ID(x));
            }
            else if (s[0] == 'D')  //DUP命令
                setID.push(setID.top());
            else {     //需要兩個集合做運算的命令
                SET x1, x2, x;
                //堆疊最頂層的集合給X1 ;之後把堆疊最頂層彈出(刪除)
                x1 = idCatch[setID.top()];  setID.pop();  
                //堆疊最頂層的集合給X2 ;之後把堆疊最頂層彈出(刪除)
                x2 = idCatch[setID.top()];  setID.pop();
                if (s[0] == 'U')  //聯集命令
                    set_union(ALL(x1), ALL(x2), INS(x));
                else if (s[0] == 'I')  //交集命令
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                else {   //add命令
                    x = x2;
                    x.insert(ID(x1));
                }
                //處理完的輸出集合 加回setID
                setID.push(ID(x));
            }
            //印出最後堆疊集合的層數
            cout << idCatch[setID.top()].size() << endl;
        }
        cout << "***" << endl;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
