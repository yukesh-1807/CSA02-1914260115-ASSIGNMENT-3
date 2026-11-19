
#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort: Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);
}

void selectionSort(int a[], int n)
{
    int comparisons = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }
    }

    printf("Selection Sort: Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);
}

void insertionSort(int a[], int n)
{
    int comparisons = 0, shifts = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                shifts++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }

    printf("Insertion Sort: Comparisons = %d, Shifts = %d\n",
           comparisons, shifts);
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10000)
    {
        printf("Invalid size\n");
        return 1;
    }

    int original[10000], a[10000];

    printf("Enter register numbers:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &original[i]);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    bubbleSort(a, n);
    printf("Sorted: ");
    display(a, n);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    selectionSort(a, n);
    printf("Sorted: ");
    display(a, n);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    insertionSort(a, n);
    printf("Sorted: ");
    display(a, n);

    return 0;
}
