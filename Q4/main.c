
#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

float rain[DISTRICTS][MONTHS];

void annualTotals()
{
    int i, j;
    float total;

    printf("\nAnnual Rainfall:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        total = 0;

        for (j = 0; j < MONTHS; j++)
            total += rain[i][j];

        printf("District %d = %.2f mm\n", i + 1, total);
    }
}

void monthlyAverages()
{
    int i, j;
    float total;

    printf("\nMonthly State Averages:\n");

    for (j = 0; j < MONTHS; j++)
    {
        total = 0;

        for (i = 0; i < DISTRICTS; i++)
            total += rain[i][j];

        printf("Month %d = %.2f mm\n",
               j + 1, total / DISTRICTS);
    }
}

void wettestMonth()
{
    int i, j, district = 0, month = 0;
    float maximum = rain[0][0];

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            if (rain[i][j] > maximum)
            {
                maximum = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nWettest District-Month:\n");
    printf("District = %d, Month = %d, Rainfall = %.2f mm\n",
           district + 1, month + 1, maximum);
}

void deficientDistricts()
{
    int i, j, count = 0;
    float stateTotal = 0, districtTotal;

    for (i = 0; i < DISTRICTS; i++)
        for (j = 0; j < MONTHS; j++)
            stateTotal += rain[i][j];

    stateTotal /= DISTRICTS;

    printf("\nDistricts below 60%% of state average:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        districtTotal = 0;

        for (j = 0; j < MONTHS; j++)
            districtTotal += rain[i][j];

        if (districtTotal < 0.60f * stateTotal)
        {
            printf("District %d\n", i + 1);
            count++;
        }
    }

    if (count == 0)
        printf("No deficient districts\n");
}

int main()
{
    int i, j;

    /* Automatically initialize rainfall data */
    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            rain[i][j] = 100 + (i * 2) + j;
        }
    }

    annualTotals();
    monthlyAverages();
    wettestMonth();
    deficientDistricts();

    return 0;
}
