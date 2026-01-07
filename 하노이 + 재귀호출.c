#include <stdio.h>

#define N 3       //（円盤の数）
 
int st[N];// 円盤の位置を保持する配列(プラス課題用) 利用は任意

void print_t(){
    int i;

    for(int t=1;t<=3;t++){
        printf("T %d: [", t);
        for(i=N-1;i>=0;i--){
            if(st[i]==t){
                printf(" %d", i+1);
            }
        }
        printf(" ]\n");
    }
    printf("\n");
}

void hanoi (int n, int from, int to, int work){

    if(n == 0) return;

    // ① n−1枚を作業用(work)へ
    hanoi(n-1, from, work, to);

    // ② n番目の円盤を from→to へ移動
    printf("%d: from %d to %d\n", n, from, to);

    st[n-1] = to;   // 円盤の位置を更新
    print_t();      // 現在の塔の状態を表示

    // ③ 残りの n−1枚を目的地へ
    hanoi(n-1, work, to, from);

}

void main(){
    int from=1; //移動元の杭ID
    int to= 3; //移動先の杭ID
    int work =2;//作業用(空)の杭ID
    int i;

    for (i=0;i<N;i++){// 円盤の位置をすべてS（=1）に初期化(プラス課題用)　利用は任意
        st[i]=1;
    }

    print_t(); //円盤の(初期)状態を出力
    hanoi(N,from,to,work);//N:全円盤の数、from:移動元の杭ID、to：移動先の杭ID、work:作業用(空)の杭ID


}