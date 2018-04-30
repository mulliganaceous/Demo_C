#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char string[20];
    
    printf("Enter a number n\n");
    scanf("%d", &n);
    
    int i;
    char *largest = NULL; /* Largest string */
    for(i=0; i<n; i++) //gets n words from the user 
    {
        /* Enter word */
        printf("Enter a word: \n");
        scanf("%19s", string);

        if (largest == NULL)
            largest = string;
        else if (strcmp(largest, string) > 0)
            largest = string;
    }
}