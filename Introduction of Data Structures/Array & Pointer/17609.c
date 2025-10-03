
#include <stdio.h>
#include <string.h>

char word[100001];

int comp(int p1, int p2)
{
    while (p1 < p2)
    {
        if (word[p1] != word[p2])
            return 1;
        p1++;
        p2--;
    }
    return 0;
}

int func()
{
    scanf("%100000s", word);

    int p1 = 0;
    int p2 = strlen(word) - 1;

    int check = 0;

    while (p1 < p2)
    {
        if (word[p1] != word[p2])
        {
            if (check)
                return 2;

            if (word[p1 + 1] == word[p2])
                if (!comp(p1 + 1, p2))
                    return 1;

            if (word[p1] == word[p2 - 1])
            {
                if (!comp(p1, p2 - 1))
                    return 1;
            }

            else
                return 2;

            check = 1;
        }
        p1++;
        p2--;
    }
    if (check)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", func());
    }
    return 0;
}
