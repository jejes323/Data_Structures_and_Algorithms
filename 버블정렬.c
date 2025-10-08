#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void print_a(int a[]) {

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

void sort(int a[]) {

    int tmp = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    print_a(a);
}

int main() {
    
    int a[N] = {0};
    srand((unsigned int)time(NULL));
    
    for(int i = 0; i < N; i++) {
        a[i] = rand()%100;
    }

    printf("Start:\n");
    print_a(a);

    printf("Finish:\n");
    sort(a);

}