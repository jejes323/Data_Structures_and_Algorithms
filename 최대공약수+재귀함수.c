#include <stdio.h>

int koyaku(int a, int b) {
    printf("koyaku(%d, %d) 呼び出し\n", a, b);

    if (b == 0) {
        printf("koyaku(%d, %d) 戻り値: %d\n", a, b, a);
        return a;
    } else {
        int result = koyaku(b, a % b);
        printf("koyaku(%d, %d) 戻り値: %d\n", a, b, result);
        return result;
    }
}

void main(void){
    printf ("%d\n",koyaku(72,16));
}