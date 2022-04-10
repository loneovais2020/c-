#include <stdio.h>
int main(){
int i,j=0;
int numOfElements,choice,val,newVal,newValIndex;
  printf("Enter number of elements\n");
    scanf("%d", &numOfElements);
      int arr[numOfElements];
      int reverseArr[numOfElements];
    for(int i=0;i<numOfElements; i++)
    {
printf("Enter Element No.%d\n",i);
        scanf("%d", &arr[i]);

    }
  for(int i=numOfElements-1;i>=0;i--)
  {
    reverseArr[j]=arr[i];
    j++;
  }
  printf("Reversed Array:\n");
  for(int i=0;i<numOfElements;i++)
  {
  
  printf("%d\n",reverseArr[i]);
    }
    return 0;
}
