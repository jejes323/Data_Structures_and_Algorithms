#include <stdio.h>

int kaijo(int a){
    int b;
    if (a==1) {
        b = 1;
    } else {
        b = a * kaijo(a-1);
    }
    return b;

}

void main(void){
    printf ("%d\n",kaijo(10));
}