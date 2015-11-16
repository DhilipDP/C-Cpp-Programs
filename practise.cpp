#include<stdio.h>
 
int main()
{
    char *s = "Geeks Quiz";
    int n = 7;
    printf("%.*s",n, s);  // width is specified  using .*
    return 0;
}
