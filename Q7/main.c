#include <stdio.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 500000

int main()
{
    int count[MAX_CANDIDATES + 1] = {0};
    int candidate[MAX_CANDIDATES];
    int votes, candidates;
    int i, vote;
    int valid = 0, invalid = 0;
    int temp;

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > MAX_CANDIDATES)
    {
        printf("Invalid candidate count\n");
        return 0;
    }

    printf("Enter number of votes: ");
    scanf("%d", &votes);

    if (votes < 1 || votes > MAX_VOTES)
    {
        printf("Invalid vote count\n");
        return 0;
    }

    printf("Enter votes:\n");

    for (i = 0; i < votes; i++)
    {
        scanf("%d", &vote);

        if (vote >= 1 && vote <= candidates)
        {
            count[vote]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    /* Store candidate numbers */
    for (i = 0; i < candidates; i++)
        candidate[i] = i + 1;

    /* Sort candidates by votes in descending order */
    for (i = 0; i < candidates - 1; i++)
    {
        int j;

        for (j = 0; j < candidates - i - 1; j++)
        {
            if (count[candidate[j]] <
                count[candidate[j + 1]])
            {
                temp = candidate[j];
                candidate[j] = candidate[j + 1];
                candidate[j + 1] = temp;
            }
        }
    }

    printf("\nValid Votes = %d\n", valid);
    printf("Invalid Votes = %d\n", invalid);

    printf("\nCandidate Vote Details:\n");

    for (i = 0; i < candidates; i++)
    {
        printf("Candidate %d = %d votes\n",
               candidate[i], count[candidate[i]]);
    }
   
    if (count[candidate[0]] == count[candidate[1]])
    {
        printf("\nElection Result: Tie\n");
        printf("Candidates with highest votes:");

        for (i = 0; i < candidates; i++)
        {
            if (count[candidate[i]] == count[candidate[0]])
                printf(" %d", candidate[i]);
            else
                break;
        }

        printf("\n");
    }
    else
    {
        printf("\nWinner: Candidate %d\n", candidate[0]);
    }

    return 0;
}
