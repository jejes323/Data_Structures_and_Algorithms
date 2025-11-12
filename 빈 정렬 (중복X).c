#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10 //整列する要素数
#define M 100 //各要素がとり得る数の範囲

void print_a(int a[]){
    int i;
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
}  


void sort(int a[]){ //ビンソートをここに実装
    int bin_count = 10;        // 0〜99を10個のビンに分ける（0-9, 10-19, ... 90-99）
    int bins[10][N];           // 各ビンに最大 N 個の要素を格納できる
    int count[10] = {0};       // 各ビン内の要素数をカウント

    for (int i = 0; i < N; i++) {
        int index = a[i] / 10;
        bins[index][count[index]++] = a[i];
    }

    for (int i = 0; i < bin_count; i++) {
        for (int j = 1; j < count[i]; j++) {
            int key = bins[i][j];
            int k = j - 1;
            while (k >= 0 && bins[i][k] > key) {
                bins[i][k + 1] = bins[i][k];
                k--;
            }
            bins[i][k + 1] = key;
        }
    }


    int idx = 0;
    for (int i = 0; i < bin_count; i++) {
        for (int j = 0; j < count[i]; j++) {
            a[idx++] = bins[i][j];
        }
    }
}

void main(void){
    int a[N]={6,8,1,9,10,2,4,7,3,5};//固定配列の初期化
    int i,tmp;
    
    // 動作検証用の配列作成(ランダムは0-99の整数)
    srand((unsigned int)time(NULL));

    for(i=0;i<N;i++){
        while(1){
            int num = rand()%M;
            int duplicate = 0;
            for(int j=0;j<i;j++){
                if(a[j]==num){ duplicate=1; break; }
            }
            if(!duplicate){
                a[i] = num;
                break;
            }
        }
    }

    for (i=0;i<N;i++){
        a[i]=rand()%M;//課題1 デバッグ時に配列を固定したい場合は、この行をコメントアウト
        //a[i]=rand()%(N-1);//課題2 重複した数がある場合
    }

    printf ("Start:\n");//配列の初期状態を出力
    print_a(a);

    sort(a);
    
    printf ("Finish:\n");
    print_a(a);//配列の最終状態を出力
}