#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* s[10];
    gets(s);
    int i;
    i=0;

    if((strlen(s)%2)!= 0)
        return -1;

    int n,k;

    for(n=0;n<(strlen(s));n++)
    {
        k=0;
        while (i<strlen(s))
        {
            //printf("pr2 ");
            if(((s[i]='(')&&(s[i+1]=')'))||((s[i]='{')&&(s[i+1]='}')))
            {
                if(strlen(s)==2)
                    return 0;
                //printf("pr3 ");
                int j;
                //printf("pr4 ");
                for (j=0;j<=(strlen(s)-i-1);j++)
                {
                    //printf("pr5 ");
                    s[i+j]=s[i+j+2];
                }
                //printf("pr5 ");

                s[strlen(s)-2]="\0";

                k=1;
            }
            printf("%s",s);
            i++;
        }
        if(k==0)
            return -1;
    }
    return 0;
}
