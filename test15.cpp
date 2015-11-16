#include <stdio.h>
int main()
{
	
	int a=3;
	if(a > 1)
		printf("Hello");
	else if(a > 2)
		printf("hi");
	
    char check = 'a';
    switch (check)
    {
        case 1: printf("Geeks ");
         
        case 3: printf("Quiz ");
                    break;
        default: printf("GeeksQuiz");
    }
    return 0;
}
