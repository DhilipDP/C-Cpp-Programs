#include<stdio.h>

int  main(){
char *s[] = {"knowledge" , "is" , "power"};
for(int i=0 ; i<3 ; i++)
	printf("%u %u %s\n",&s[i],s[i],s[i]);
char **p;
p = s;
printf("%s\n",++*p);
printf("%u\n",p);
printf("%s\n",*p++);
printf("%u\n",p);
printf("%s\n",++*p);
}
