
//Task 3 Update the code so that correct string size
    //gets printed
    //whats_wrong_1();



#include <stdio.h>
#include <string.h>


void whats_wrong_1()
{
    char s[50];

    printf("Enter a name: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    strcat(s, " is the best!");

    printf("\n%s\n", s);
    printf("String size: %zu\n", strlen(s));
}
int main()
{

    whats_wrong_1();


    return 0;
}
