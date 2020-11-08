  
// This program includes the length of '\0' , Null Character
#include <stdio.h>
#define MAX 100

int get_len(int ,char *);

int main(void)
{
    char string[MAX];

    printf("Input a string: ");
    fgets(string, sizeof(string), stdin);

    printf("Length = %d", get_len(0, string));
    
    return 0;

}

int get_len(int n, char *string)
{

    if (string[n] == '\0')
    {
        return n++; 
    }
    else
    {
        return get_len(n + 1, string); //
    }
}
