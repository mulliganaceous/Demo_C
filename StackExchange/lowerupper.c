#include <stdio.h>
#include <ctype.h>

int main(void)
{
    unsigned char a[50];
    scanf("%s", a);

    int i;
    for (i=0; a[i] != '\0'; i++) {
        if (isupper(a[i]))
            a[i] = (unsigned) tolower(a[i]);
        else if (islower(a[i]))
            a[i] = (unsigned) toupper(a[i]); 
        /* Do nothing for all other characters */
    }
    printf("%s",&a);
    return 0;
}