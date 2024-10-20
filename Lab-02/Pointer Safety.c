#include <stdio.h>
#include <stdlib.h>  

int main() {
    
    char *ptrName;
    char fullName[] = "Md. Ishmam Uddin";
    ptrName = fullName;  
    printf("My name is %s\n", ptrName);

    
    int *ptrSalary = malloc(sizeof(int));
    if (ptrSalary == NULL) {  
        printf("Memory allocation failed\n");
        return 1;
    }
    *ptrSalary = 1000;  
    printf("My salary is %d\n", *ptrSalary);

    
    free(ptrSalary);
    
    *ptrSalary = 2000;  
    printf("My salary is %d\n", *ptrSalary);

    
    char *alphabet = (char *)malloc(27);   terminator
    if (alphabet == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }
    alphabet[26] = '\0';  
    printf("Alphabet A-Z: %s\n", alphabet);

   
    for (int i = 0; i < 26; i++) {
        printf("%c", 'Z' - i);  
    }
    printf("\n");

    
    free(alphabet);

    return 0;
}
