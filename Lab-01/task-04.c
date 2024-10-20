//Task 4 Update the code so that uncessary information
    //does not get printed
    //null_problem();


#include<stdio.h>
  #include<string.h>


   void whats_wrong_2()
{
    char s1[20] = "Network";
    char s2[20] = " Security";
    char s3[40];

    strcpy(s3, s1);
    strcat(s3, s2);

    printf("%s\n", s3);


    strncpy(s1, s3, sizeof(s1) - 1);
    s1[sizeof(s1) - 1] = '\0';

    printf("%s\n", s1);
}

int main()
{



    whats_wrong_2();


    return 0;
}

