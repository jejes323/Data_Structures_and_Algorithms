#include <stdio.h>
#include <string.h>

int text_search(char t[], char p[]) {
    int n = strlen(t);
    int m = strlen(p);

    int i = 0; // 텍스트 시작 위치
    while (i <= n - m) {
        int j = 0; // 패턴 인덱스
        while (j < m) {
            printf("*t= %02d, *p= %02d\n", i + j, j); // 디버그 출력
            if (t[i + j] != p[j])
                break;
            j++;
        }
        if (j == m) {
            return i + 1; // 패턴 전체 일치
        }
        i++; // 다음 시작 위치로 이동 (naive 방식 유지)
    }

    return -1;  // 見つからない
}

int main(void) {
    char t[] = "cadabeabafababc"; // 検索対象
    char p[] = "ababc";           // パターン
    int r;

    r = text_search(t, p);

    if (r != -1) {
        printf("Found at %d\n", r);
    } else {
        printf("Not found\n");
    }
}