//occurence counter of array elements
//Ovais Tariq Lone
//06/04/2022
#include <stdio.h>
void main(){
   int numOfElements;
   int num;
   int counter=0;
   printf("Enter the no. of the elements to be stored in the array\n");
   scanf("%d",&numOfElements);
   int arr[numOfElements];
    for (int i = 0; i <numOfElements ; i++)
    {
printf("Enter Element\n");
scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched in the array\n");
   scanf("%d",&num);
 for (int i = 0; i <numOfElements ; i++)
    {
    if (arr[i]==num)
    {
        counter++;
    }
    
    }
    if (counter>0)
    {
         printf("occurences of %d is %d\n",num,counter);
   
    }
    else
    {
           printf("Entered element  %d is not found\n",num);
    }
    
    
   
}
