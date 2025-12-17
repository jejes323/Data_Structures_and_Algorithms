#include <stdio.h>

#define N 5     //品物の種類
#define M 17 // サイズ0があるので、最大のサイズ16+1

int s[N]={2,3,5,7,9};//品物のサイズ　size
int v[N]={2,4,7,11,14};//品物の価値　value
 
void print_a(int t[],int c[]){ //表(合計価値と最後の品物ID)の表示
    int i,j;
    
    printf("SIZE_N: ",i);
    for (i=0;i<M;i++){
        printf("%02d ",i);
    }
    printf("\nVALUE_: ",i);
    for (i=0;i<M;i++){
        printf("%02d ",t[i]);
    }
    printf("\nOBJ_ID: ",i);    
    for (i=0;i<M;i++){
        printf("%02d ",c[i]);
    }
    printf("\n",i);

}

void print_list(int t[],int c[]){ //内容物の表示 
    int m, cur;

    printf("\n入っているもの\n");

    for (m = 0; m < M; m++) {
        printf("M=%02d: ", m);

        cur = m;
        if (c[cur] == -1) {
            printf(" ");
        } else {
            while (cur > 0 && c[cur] != -1) {
                printf("%02d ", c[cur]);
                cur -= s[c[cur]];
            }
        }
        printf("\n");
    }
}

void dp(int t[],int c[]){ //表(合計価値と最後の品物ID)の計算
    int i, j;
    int rp; // 新たに選択した場合の合計価値

    for (i = 0; i < N; i++) { 
        for (j = s[i]; j < M; j++) {  
            rp = t[j - s[i]] + v[i]; 
            if (rp > t[j]) {
                t[j] = rp;
                c[j] = i; 
            }
        }
        printf("N <= %d\n", i);
        print_a(t, c); 
    }
}


void main(){
    int i,j;
    int t[M]={0};   //合計価値(total)
    int c[M];       //最後に選んだ品物ID(choice)
   
    for (i=0;i<M;i++){
        c[i]=-1; //最後に選んだ品物ID(choice）の初期化　何も選択されていない場合：-1
    }

    dp(t,c); //表(合計価値と最後の品物ID)の計算 dynamic programming

    print_list(t,c); //内容物の表示 


}