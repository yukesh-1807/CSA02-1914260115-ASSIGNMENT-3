#include <stdio.h>
#include <string.h>

#define MAX 500
#define LEN 31

int main()
{
    char names[MAX][LEN];
    char temp[LEN];
    char search[LEN];

    int n, i, j;
    int comparisons = 0;
    int low, high, mid, found = -1;

    printf("Enter number of names: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of names\n");
        return 0;
    }

    getchar();

    printf("Enter names:\n");

    for (i = 0; i < n; i++)
    {
        fgets(names[i], LEN, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    /* Bubble sort using strcmp and strcpy */
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted Names:\n");

    for (i = 0; i < n; i++)
        printf("%s\n", names[i]);

    /* Display duplicate names */
    printf("\nDuplicate Names:\n");

    for (i = 0; i < n - 1; i++)
    {
        if (strcmp(names[i], names[i + 1]) == 0)
        {
            if (i == 0 ||
                strcmp(names[i], names[i - 1]) != 0)
                printf("%s\n", names[i]);
        }
    }

    printf("\nEnter name to search: ");
    fgets(search, LEN, stdin);
    search[strcspn(search, "\n")] = '\0';

    /* Binary search */
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        comparisons++;

        if (strcmp(names[mid], search) == 0)
        {
            found = mid;
            break;
        }
        else if (strcmp(names[mid], search) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (found != -1)
        printf("Name found at index %d\n", found);
    else
        printf("Name not found\n");

    printf("Comparison count = %d\n", comparisons);

    return 0;
}
