#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int text_search(char t[],char p[]){ //テキスト t に パターン p があるか検索する関数(返り値：ない場合－1,ある場合何文字目か)
    int i=0,j=0,n,m;
    int *next;
    n = strlen(t);
    m = strlen(p);
    next = (int*) malloc(sizeof(int) * m); 

	i = -1;  
    next[0] = -1;
    for (j=1; j <m;  j++) {
            while  ( i >= 0 && p[j-1] != p[i] ) {
                i = next[i];
            }
            i = i+1;
            if  (p[j] != p[i] ) next[j]=i;
            else  next[j] = next[i];
     }

    // next を表示
    for (i=0;i<m;i++){
        printf("%d, ",next[i]);
    }
    printf("\n");
    
    //以下にKMPの照合を実装

    i = 0;
    j = 0;
    while (i < n && j < m) {
        if (j >= 0) {
            printf("*t= %02d, *p= %02d\n", i, j);
        }

        if (j == -1 || t[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }

    free(next);

    if (j == m) return i - j;
    else return -1;

}

void main(void){
    char t[]="cadabeabafababc";//検索対象のテキスト
    char p[]="ababc";//検索したいパターン    

    int r;//関数の返り値 

    r = text_search(t,p);

    if (r != -1){
        printf("Found at %d \n",r+1);
    } else {
        printf("Not found\n");
    }
    
}