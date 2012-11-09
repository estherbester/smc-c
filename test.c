#include <stdio.h>
#include <string.h>

int main (void){

    char * q;

    q = "Hello";
    char name[] = {'d', 'o', 'u', '\0', 'n'};

    printf("%d", strlen(name));
    printf("\n");
    printf("%s", name);
    printf("\n");
/*    printf("%d", strlen(q));
    printf(q);
    printf("\n");
    
    printf("%s", q);
    printf("\n");

    printf("%c", *q);
    printf("\n");

    char x = *(q+2);
    printf("%c", x);
*/
    printf("\n");
    return 0;
}
