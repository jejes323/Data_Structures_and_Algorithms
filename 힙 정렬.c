#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N_MAX 11// 配列サイズ 
#define N 10 

void print_a_h(int a[]){
    int i,j,k=1;
    for (i=1;i<=N;i++){
        if  (i == k ) {
            printf("\n");
            k=k*2;
            }
        for (j=1;j<=(N)/(k+1);j++)  printf("   ");
        printf("%3d",a[i]);
    }
    printf("\n");
}  

void print_a(int a[]){
    int i;
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
}  

void swap(int a[],int i,int j){
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void downheap(int a[], int s ,int e){
    int parent = s;
    int child = 2 * parent;

    printf("start=%d,end=%d\n", s, e);

    while (child <= e) {
        if (child + 1 <= e && a[child] < a[child + 1]) {
            child++;
        }
        if (a[parent] >= a[child]) break;

        swap(a, parent, child);
        parent = child;
        child = 2 * parent;
    }

    print_a_h(a);
}

void sort(int a[]){ //再帰呼び出しを用いたクイックソートをここに実装
    int i;

    for (i = N / 2; i >= 1; i--) {
        downheap(a, i, N);
    }

    for (i = N; i >= 2; i--) {
        swap(a, 1, i);
        downheap(a, 1, i - 1);
    }

    printf("Downheap Done\n");
     
}

void main(void){
    int a[N_MAX]={-1,13,25,18,12,5,21,15,17,9,20};//固定配列の初期化
    int i,tmp;
    
    // 動作検証用の配列作成(ランダムは0-99の整数)
    srand((unsigned int)time(NULL));
    for (i=1;i<=N;i++){
        a[i]=rand()%100;//デバッグ時に配列を固定したい場合は、この行をコメントアウト
    }

    printf ("Start:\n");//配列の初期状態を出力
    print_a(a);

    sort(a);
    
    printf ("Finish:\n");
    print_a(a);//配列の最終状態を出力
}