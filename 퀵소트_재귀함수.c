#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 //配列の数

void print_a(int a[]){ //配列の中身を表示
    int i;
    for (i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
}  

// 配列(第1引数)の2つ（第2引数と第3引数）の中を入替
void swap(int a[],int i,int j){ 
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    print_a(a); 
}


void sort(int a[],int s, int e){

    if (s >= e) return;

    int pivot = a[(s + e) / 2];
    int i = s;
    int j = e;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a, i, j);
            i++;
            j--;
        }
    }

    if (s < j)
        sort(a, s, j);

    if (i < e)
        sort(a, i, e);

}


void main(void){
    int a[N]={0},i,tmp;
    srand((unsigned int)time(NULL));//乱数の種の設定
    for (i=0;i<N;i++){
        a[i]=rand()%100;  //乱数の発生
    }
    printf ("Start:\n");
    print_a(a);

    sort(a,0,N-1); //sortの呼び出し
    
    printf ("Finish:\n");
    print_a(a);
}