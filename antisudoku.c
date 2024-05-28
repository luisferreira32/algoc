#include <stdio.h>
#include <string.h>

int main()
{
    int t, num, index, row;
    unsigned char antisudoku[9] = {0, 13, 26, 28, 41, 51, 56, 66, 79};
    char buff[11], board[81];

    scanf("%d\n", &num);

    for (t = 0; t < num; t++)
    {
        // read
        for (row = 0; row < 9; row++)
        {
            fgets(buff, 11, stdin);
            memcpy((void *)&board[row * 9], (void *)buff, 9);
        }

        // swap the dot values to ensure a proper anti-sudoku
        // .xx   xxx   xxx
        // xxx   x.x   xxx
        // xxx   xxx   xx.
        //
        // x.x   xxx   xxx
        // xxx   xx.   xxx
        // xxx   xxx   .xx
        //
        // xx.   xxx   xxx
        // xxx   .xx   xxx
        // xxx   xxx   x.x
        for (index = 0; index < 9; index++)
        {
            // 1, 9 ASCII == 49, 57
            if (board[antisudoku[index]] == 57)
            {
                board[antisudoku[index]] = 49;
            }
            else
            {
                board[antisudoku[index]]++;
            }
        }

        for (row = 0; row < 81; row += 9)
        {
            printf("%.*s\n", 9, &board[row]);
        }
    }
    return 0;
}
