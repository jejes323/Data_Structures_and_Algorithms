#include <stdio.h>

#define N 5

int q[N] = {0};      // 添え字行目のクイーンの配置番号(添え字 行番号y)　
int flag_x[N] = {0}; // 添え字列目が利き筋かのフラグ(添え字
                     // 列番号x)　利き筋でない:0、利き筋：1
int flag_n1[2 * N - 1] = {
    0}; // 右上斜めの利き筋のフラグ(添え字 x+y)　利き筋でない:0、利き筋：1
int flag_n2[2 * N - 1] = {0}; // 右下斜めの利き筋のフラグ(添え字
                              // yーx+(N-1))　　利き筋でない:0、利き筋：1

void print_a() { // クイーン位置(ｑ「N]ｑ「N])表示
  int i, j;
  printf("queen position\n");
  for (j = 0; j < N; j++) {
    for (i = 0; i < N; i++) {
      if (q[j] == i) {
        printf("q ");
      } else
        printf("0 ");
    }
    printf("\n");
  }
}

int q_check(
    int x,
    int y) { // 引数の座標(x,y)が利き筋か判定する関数、配置可能：1、利き筋なので配置不可能：０

  if (flag_x[x] || flag_n1[x + y] ||
      flag_n2
          [y - x +
           (N -
            1)]) { // 　x,yに配置可能か（利き筋ではないかなど）を判定する条件を記載
    return 0;      // 利き筋などで配置不可の場合
  } else {
    return 1; // 配置可能の場合
  }
}

int n_queen(int y) { // 引数(y)行目以降のクイーンの配置を探索

  int x;

  if (y == N) { // もしそれがN個目 y==N
    print_a();  // 成功した配置を出力
    printf("\n");
    return 1; // 配置成功
  }

  for (x = 0; x < N;
       x++) {            // 各列を探索 場所(y,0) (y,1), (y,2)…(y,N-1)を繰り返す
    if (q_check(x, y)) { // その場所が利き筋でない
      // クイーンを置く&配置・利き筋flag設定
      q[y] = x;
      flag_x[x] = 1;
      flag_n1[x + y] = 1;
      flag_n2[y - x + (N - 1)] = 1;

      if (n_queen(y + 1)) { // y+1以降のコマが配置できたら
        // 配置成功→置いたクイーンを取り除く& 配置・利き筋flag削除
        q[y] = -1;
        flag_x[x] = 0;
        flag_n1[x + y] = 0;
        flag_n2[y - x + (N - 1)] = 0;
        // 次の解を探すため継続
      } else {
        // 配置失敗→置いたクイーンを取り除く&
        // 配置・利き筋flag削除（この先の配置を打ち切り)
        q[y] = -1;
        flag_x[x] = 0;
        flag_n1[x + y] = 0;
        flag_n2[y - x + (N - 1)] = 0;
      }
    }
  }
  return 0; // 全部探索したが失敗した場合
}

void main() {
  int i;

  for (i = 0; i < N; i++) { // q初期化　未配置:-1, 配置済: 列番号
    q[i] = -1;
  }

  n_queen(0); // 1列目(C言語でいうと添え字0)以降の配置を行う
}