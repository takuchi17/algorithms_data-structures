#include <stdio.h>

int main(void)
{
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if (i != N - 1)
            printf(" ");
    }

    printf("\n");

    for (int i = 1; i < N; i++)
    {
        int currentEle = A[i];
        int j = i - 1;
        while (j >= 0 && currentEle < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = currentEle;

        for (int k = 0; k < N; k++)
        {
            printf("%d", A[k]);
            if (k != N - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}