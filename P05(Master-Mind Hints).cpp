#include <stdio.h>
#include <ctime>
#include <algorithm>


#define IN "P05IN.txt"
#define OUT "P05OUT.txt"


int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int game = 0;
    int leng;
    while (scanf("%d", &leng) == 1 && leng) {
        int* s = new int[leng];     //store question
        int* g = new int[leng];     //store guess
        int* st = new int[leng];    //copy question use for operation
        printf("Game %d\n", ++game);

        //read question
        for (int i = 0; i < leng; i++) {
            scanf("%d", &s[i]);
        }


        bool flag = true;
        while (flag) {
            int A = 0;     //number and location both correct
            int B = 0;     //number is correct but location is wrong
            for (int i = 0; i < leng; i++) {
                scanf("%d", &g[i]);    //read guess number value
                //check A
                st[i] = s[i];
                if (st[i] == g[i]) {
                    A++;
                    st[i] = -1;
                    //g[i] = -1;
                }
            }
            if (g[0] == 0) {
                flag = false;
            }
            else {
                for (int j = 1; j <= 9; j++)
                {
                    // named for counting same number in Answer & Guess
                    int iCntAns = 0;
                    int iCntGue = 0;
                    for (int i = 0; i < leng; i++)
                    {
                        if (j == s[i])
                            iCntAns++;
                        if (j == g[i])
                            iCntGue++;
                    }
                    B += std::min(iCntAns, iCntGue);
                }
                printf("(%d,%d)\n", A, B-A);
            }
        }
        delete[] s, g, st;
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n", cost);


    return 0;
}
