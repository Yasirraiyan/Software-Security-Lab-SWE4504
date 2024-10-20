


    //Task 1 Update the code so that all the elements
    //of dis array is 0
    //call_clear_fn();


#include<stdio.h>
#include<string.h>


  void AvarageFinder(int array_v[],int size)
  {

      double sum=0;
      for(int i=0;i<size;++i)
      {
          array_v[i]=i+1;
          sum=sum+array_v[i];

      }
      printf("Sum: %lf\n",sum);
      printf("Avarage:%lf\n",sum/size);
  }
  int main()
  {

      int v[10];
      AvarageFinder(v,10);

        return 0;
  }
