//Task 2 Update the code so that only the defined size
    //gets printed
    //take_st();
#include<stdio.h>
  #include<string.h>

    void take_info()
    {

        int age;
        char name[10];
        char address[10];
        char email[15];

        printf("Enter your Name:");

        fgets(name,sizeof(name),stdin);
        name[strcspn(name,"\n")]='\0';

        printf("Enter your Address:");
        fgets(address,sizeof(address),stdin);
        address[strcspn(address,"\n")]='\0';

        printf("Enter your Email:");
        fgets(email,sizeof(email),stdin);
        email[strcspn(email,"\n")]='\0';

        printf("Enter your Age:");
        scanf("%d",&age);
        printf("\n\nName: %s\n", name);
        printf("Age: %d\n", age);
        printf("Address: %s\n", address);
        printf("Email: %s\n", email);
    }
    int main()
{
    int v[10];

    take_info();
    return 0;
}
