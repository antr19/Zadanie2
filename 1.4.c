#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char s[11];
    gets(s);
    int i;

    if((strlen(s)%2)!= 0)
        return -1;

    int b, a, len = strlen(s);

    a = 0;
    b = 0;

    for(i = 0; i < len; i++)
    {
        if (s[i] == '(')
            a +=1;
        else if ((s[i] == ')')&&(a>0))
            a -= 1;
        else if (s[i] == '{')
            b +=1;
        else if ((s[i] == '}')&&(b>0))
            b -= 1;
        else
            return -1;
    }
    if ((a != 0) || (b != 0))
        return -1;
    return 0;
}
