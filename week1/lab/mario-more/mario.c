#include <cs50.h>
#include <stdio.h>

void create_brick(int n);
int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n <= 0 || n > 8);

    create_brick(n);
}

void create_brick(int n)
{
    // for each row
    for (int i = 1; i <= n; i++)
    {
        // for each column (n * 2 + 2)
        for (int j = 1; j <= (2 * n + 2); j++)
        {
            // middle
            if (j == 1 + n || j == 2 + n)
            {
                printf(" ");
            }
            // right pyramid
            else if (j <= n + 2 + i && j > n)
            {
                printf("#");
            }
            // left pyramid
            else if (j <= n && j > n - i)
            {
                printf("#");
            }
            else if (j <= n)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}