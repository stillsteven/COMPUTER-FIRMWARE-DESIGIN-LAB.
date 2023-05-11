#include <stdio.h>    
#include <string>     
#include <iostream>   
#include <ctime>
#include <map>        //表格容器工具  
#include <queue>      //佇列工具 


#define IN "P18IN.txt"
#define OUT "P18OUT.txt"

using namespace std;


int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int T, M, id;   //T個隊伍 每對有M個成員  以及其ID 
    int qCnt = 0;   //用來印出處理的佇列數

    while (cin >> T && T != 0) {
        //紀錄每個ID的所屬隊伍
        map<int, int > tid;
        for (int t = 0; t < T; t++) {
            cin >> M;
            for (int m = 0; m < M; m++) {
                cin >> id;
                tid[id] = t;     //標記id 所屬隊伍 
            }
        }
        //處理佇列命令
        queue <int> qt;           //紀錄存在的隊伍
        queue <int> qid[1000];    //紀錄存在的id 
        printf("Scenario #%d\n", ++qCnt);     // 印出處理的佇列
        string s;     //讀命令字串s
        while (cin >> s && s[0] != 'S') {
            int t0;     //儲存id 的所屬隊伍
            if (s[0] == 'E') {     //ENQUENE 命令
                cin >> id;
                t0 = tid[id];      //取得所屬隊伍
                //檢查所屬隊伍是否存在
                if (qid[t0].empty())   
                    qt.push(t0);      // 不存在則將所屬隊伍加入佇列
                qid[t0].push(id);     //id 加入佇列
            }
            else {        //s[0] == 'D' dequeue 命令
                t0 = qt.front();      //取得隊首的所屬隊伍
                cout << qid[t0].front() << endl;    // 印出要離隊的id 
                qid[t0].pop();       //刪除離隊id 
                // 檢查隊伍是否還有id 在佇列中
                if (qid[t0].empty())
                    qt.pop();        //如果隊伍成員全部離隊 則刪除隊伍
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
