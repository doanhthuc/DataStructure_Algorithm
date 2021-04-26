#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *ltrim(char s[])
{

    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    strcpy(&s[0], &s[i]);

    return s;
}

char *rtrim(char s[])
{

    int i = strlen(s) - 1;
    while (s[i] == ' ')
    {
        i--;
    }
    s[i + 1] = '\0';

    return s;
}

char *trim(char s[])
{

    rtrim(ltrim(s));
    char *ptr = strstr(s, "  ");
    while (ptr != NULL)
    {
        strcpy(ptr, ptr + 1);
        ptr = strstr(s, "  ");
    }
    return s;
}

int main()
{
    char *s;
    scanf("%s", &s);
    s = trim(s);
    printf("%s", s);
    return 0;
}