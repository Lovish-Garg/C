// In this function I have made a custom strrev function to reverse the string
#include <stdio.h>
#include<string.h> 
#define MAX 100

char *strrev(char string[], int, int);

int main() 
{
	//code
	int t;
    printf("Input number of strings to reverse: ");
	scanf("%d\n", &t);
    
	while (t--)
	{
	    char string[MAX];
	    scanf("%s", string); // It won't take Multi-strings 
	    printf("%s\n", strrev(string, 0, strlen(string) - 1));
	}
	return 0;
}

char *strrev(char string[], int start, int end)
{
    if (end == 0)
    {
        return NULL;
    }
    while (start < end)
    {
        char temp = string[start];
        
        string[start] = string[end];
        string[end] = temp;

        start++;
        end--;
    }
    return string;
}
