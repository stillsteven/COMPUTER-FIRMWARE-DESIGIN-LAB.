#include <stdio.h>
#include <ctime>


#define IN "P01IN.txt"
#define OUT "P01OUT.txt"


int main() {

    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    clock_t cS = clock();

    int n;
    while (scanf("%d", &n) == 1) {
        int count = 0;
        long long lln = n;

        while (lln !=1) {
            count++;
            if (lln % 2 != 0) {
                lln = 3 * lln + 1;
            }
            else {
                lln = lln / 2;
            }
        }
        printf("%d\n", count);
    }

    clock_t cE = clock();
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    double cost = (double)(cE - cS) / CLK_TCK;
    printf("Cost time: %.2f\n" , cost);


    return 0;
}
