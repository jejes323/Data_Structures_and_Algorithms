#include <stdio.h>

int main() {
    int num1, num2;
    int smallNum;

    printf("2つの整数を入力: ");
    scanf("%d %d", &num1, &num2);

    if(num1 > num2) smallNum = num2;
    else smallNum = num1;

    while (1) {
        if (num1 % smallNum == 0 && num2 % smallNum == 0) {
            printf("%d", smallNum);
            break;
        }
        smallNum--;
    }
    
    return 0;
}