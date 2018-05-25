#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char array[10][10]);
void print_array(char array[10][10]);

int main(void)
{
    char array[10][10];
    int i, j;
    
    for (i = 0; i < 10; i++) {
        for (j = 0; j< 10; j++) {
            array[i][j] = '.';
        }
    }
    
    generate_random_walk(array);
    print_array(array);
    
    return 0;
}

void generate_random_walk(char array[10][10])
{
    int i, j, cnt, walk;
    srand((unsigned) time(NULL));
    i = 0;
    j = 0;
    cnt = 65;  // 'A'
    
    while (cnt < 65+26) {
        if (((i-1) < 0 || array[i-1][j] != '.') &&
            ((i+1) > 9 || array[i+1][j] != '.') &&
            ((j-1) < 0 || array[i][j-1] != '.') &&
            ((j+1) > 9 || array[i][j+1] != '.')) {
                break;  // Blocked Everywhere
            }
        
        walk = rand() % 4;  // Pick a random direction
        
        if (walk == 0)  {       //up
            if ((i-1) < 0 || array[i-1][j] != '.')
                continue;
            i -= 1;
            array[i][j] = cnt;
            cnt++;
        }
        else if (walk == 1)  {  //down
            if ((i+1) < 0 || array[i+1][j] != '.')
                continue;
            i += 1;
            array[i][j] = cnt;
            cnt++;
        }
        else if (walk == 2)  {  //left
            if ((j-1) < 0 || array[i][j-1] != '.')
                continue;
            j -= 1;
            array[i][j] = cnt;
            cnt++;
        }
        else if (walk == 3)  {  //right
            if ((j+1) < 0 || array[i][j+1] != '.')
                continue;
            j += 1;
            array[i][j] = cnt;
            cnt++;
        }
    }
}

void print_array(char array[][10])
{
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}
