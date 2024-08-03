#include <stdio.h>
#include <string.h>

// max rounds is also the maximum number of players if each wins one round
#define MAX_N 1000
#define MAX_NAME 33

int main()
{
    int i, j, n, score = 0, new_player = 0, scores[MAX_N] = {0}, places[MAX_N] = {0};
    char name[MAX_NAME], players[MAX_N][MAX_NAME] = {{0}}; // should be a hash map

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        memset(name, '\0', MAX_NAME);
        scanf("%s %d", name, &score);

        for (j = 0; j < n; j++)
        {
            if (j == new_player)
            {
                strcpy(players[j], name);
                new_player++;
            }

            if (strcmp(players[j], name))
            {
                continue;
            }

            scores[j] += score;
            break;
        }

        for (j = 0; j < new_player; j++)
        {
            /**
             * TODO: sort the places array based on the rules:
             * - highest to lowest
             * - the first to arrive to a certain is highest than a second arrival (i.e., previous places matter)
             */
        }
    }

    printf("%s\n", players[places[0]]);

    return 0;
}