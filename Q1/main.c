
#include <stdio.h>

int steps;

int linear_search(const int a[], int n, int key)
{
    steps = 0;

    for (int i = 0; i < n; i++)
    {
        steps++;

        if (a[i] == key)
            return i;
    }

    return -1;
}

int binary_search(const int a[], int n, int key)
{
    int low = 0, high = n - 1;
    steps = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        steps++;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int accession[] =
    {1021, 1048, 1103, 1190, 1222,
     1305, 1377, 1402, 1460, 1533};

    int keys[] = {1021, 1305, 1533, 1400};

    int n = sizeof(accession) / sizeof(accession[0]);

    printf("BINARY SEARCH RESULTS\n");

    for (int i = 0; i < 4; i++)
    {
        int pos = binary_search(accession, n, keys[i]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    printf("\nLINEAR SEARCH RESULTS\n");

    for (int i = 0; i < 4; i++)
    {
        int pos = linear_search(accession, n, keys[i]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[i], pos, steps);
    }

    return 0;
}
