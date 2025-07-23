

#include <stdio.h>

int main()
{

    int m, n;
    scanf("%d %d", &m, &n);

    int arr1[m];
    int i = 0;

    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    int arr2[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int merged[m + n];
    for (i = 0; i < m; i++)
    {
        merged[i] = arr1[i];
    }
    for (int j = 0; j < n; i++, j++)
    {
        merged[i] = arr2[j];
    }

    for (i = 0; i < (m + n); i++)
    {
        printf("%d ", merged[i]);
    }
    return 0;
}
