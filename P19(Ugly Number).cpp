#include <stdio.h>    
#include <string>     
#include <iostream>   
#include <ctime>
#include <algorithm>  //演算法工具;min()找最小值
#include <vector>     //矩陣容器工具



//#define IN "P19OUT.txt"
#define OUT "P19OUT.txt"

using namespace std;


int main() {

    //freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    vector<int> u(1, 1);         //醜數初始化
    int i2 = 0, i3 = 0, i5 = 0;              //2 ,3 ,5倍數的索引
    while (u.size() < 1500) {
        //算出下一個醜數
        int min23 = min(u[i2] * 2, u[i3] * 3);
        int nextu = min(min23, u[i5] * 5);
        u.push_back(nextu);      //醜數加入矩陣
        //更新索引
        if (u[i2] * 2 == nextu) i2++;
        if (u[i3] * 3 == nextu) i3++;
        if (u[i5] * 5 == nextu) i5++;

    }
    //印出第1500個醜數
    printf("The 1500’th ugly number is %d", u[1499]);


    clock_t cE = clock();
    //freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
