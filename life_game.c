/*
■生物Aの周囲８近傍の生物数が、
０または１・・・次の世代にはAは死滅
２または３・・・次の世代にはAは存続
４以上・・・次の世代にはAは死滅

■空白フィールドBの周囲８近傍の生物数が
３・・・次の世代にはBに生物が誕生
他・・・次の世代も空白
*/


#include <stdio.h>
#define SIZE 20 /*フィールドのサイズ*/

void initialize(int old[SIZE][SIZE], int now[SIZE][SIZE])
{
    /*配列の初期化*/
    int x, y;

    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            old[x][y] = now[x][y] = 0;
        }
    }

    /*生物の初期配置*/
    for (y = 5; y <= 15; y++) {
        old[SIZE / 2][y] = 1;
    }
}

int count(int a[SIZE][SIZE], int x, int y)
{
    /*配列aの座標（x,y）について、周囲８近傍の生物数を返す*/
    int i, j, sum = 0;

    for (j = y - 1; j <= y + 1; j++) {
        for (i = x - 1; i <= x + 1; i++) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
                if (!(i == x && j == y)) {
                    sum += a[i][j];
                }
            }
        }
    }
    return 0;
}

void regeneration(int old[SIZE][SIZE], int now[SIZE][SIZE])
{
    /*oldからnowに世代交代*/
    int x, y, neighbors;
    
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            neighbors = count(old, x, y);
            
            if (old[x][y] == 1) { // 生物が存在する場合
                if (neighbors <= 1 || neighbors >= 4) {
                    now[x][y] = 0; // 死滅
                } else { // neighbors が 2 または 3
                    now[x][y] = 1; // 存続
                }
            } else { // 空白フィールドの場合
                if (neighbors == 3) {
                    now[x][y] = 1; // 誕生
                } else {
                    now[x][y] = 0; // 空白のまま
                }
            }
        }
    }
}

void renewal(int old[SIZE][SIZE], int now[SIZE][SIZE])
{
    /*nowの内容をoldにコピーする*/
    int x, y;
    
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            old[x][y] = now[x][y];
        }
    }
}

int number(int a[SIZE][SIZE])
{
    /*aに含まれる生物の数をカウントして返す*/
    int x, y, sum = 0;
    
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            sum += a[x][y];
        }
    }
    
    return sum;
}

void display(int a[SIZE][SIZE])
{
    /*状態を表示する*/
    int x, y;
    
    printf("+");
    for (x = 0; x < SIZE; x++) {
        printf("-");
    }
    printf("+\n");
    
    for (y = 0; y < SIZE; y++) {
        printf("|");
        for (x = 0; x < SIZE; x++) {
            printf("%c", a[x][y] ? '*' : ' ');
        }
        printf("|\n");
    }
    
    printf("+");
    for (x = 0; x < SIZE; x++) {
        printf("-");
    }
    printf("+\n");
}


int main(void)
{
    int old[SIZE][SIZE], now[SIZE][SIZE], i, gen;

    initialize(old, now);

    printf("Generation = ");
    scanf("%d", &gen);

    for (i = 1; i <= gen; i++) {
        printf("Generation = %d Number = %d\n", i, number(old));
        display(old);

        regeneration(old, now);
        renewal(old, now);
    }

    return 0;
}