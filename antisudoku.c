#include <stdio.h>
#include <string.h>

int main()
{
    int t, num, i, j, diagonal, it_block_diagonal;
    char buff[11], board[81], block_diagonal[3];

    scanf("%d\n", &num);

    for (t = 0; t < num; t++)
    {
        // read
        for (j = 0; j < 9; j++)
        {
            fgets(buff, 11, stdin);
            memcpy((void *)&board[j * 9], (void *)buff, 9);
        }

        // swap diagonal values to ensure we get the proper anti-sudoku
        diagonal = -1;
        it_block_diagonal = 0;
        for (i = 0; i < 81; i++)
        {
            if (i % 9 == 0)
            {
                // line beginning, set diagonal index (== line number)
                diagonal++;
            }

            if (i % 9 == diagonal)
            {
                if (diagonal % 3 == 0)
                {
                    // reset the block [0, 1, 2], [3, 4, 5], etc.
                    it_block_diagonal = 0;
                }

                block_diagonal[it_block_diagonal] = board[i];
                it_block_diagonal++;

                for (j = 0; j < it_block_diagonal; j++)
                {
                    // TODO: change the diagonal value
                }
            }
        }

        for (i = 0; i < 81; i++)
        {
            if (i % 9 == 0 && i != 0) // skip first newline
            {
                printf("\n");
            }

            printf("%c", board[i]);
        }

        printf("\n");
    }
    return 0;
}
