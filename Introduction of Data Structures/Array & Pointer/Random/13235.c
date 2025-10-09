/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[21];
    scanf("%20s", word);

    int len = strlen(word);

    char reverse[20];
    for (int i = len - 1; i >= 0; i--)
    {
        reverse[len - i - 1] = word[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (word[i] != reverse[i])
        {
            printf("false");
            return 0;
        }
    }
    printf("true");
    return 0;
}

*/
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[21];
    scanf("%20s", word);

    int len = strlen(word);

    for (int i = 0; i < len / 2; i++)
    {
        if (word[i] != word[len - 1 - i])
        {
            printf("false");
            return 0;
        }
    }
    printf("true");
    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[21];
    scanf("%20s", word);

    int len = strlen(word);
    int p1 = 0;
    int p2 = len - 1;

    while (p1 < len)
    {
        if (word[p1] != word[p2])
        {
            printf("false");
            return 0;
        }
        p1++;
        p2--;
    }
    
    printf("true");
    return 0;
}
