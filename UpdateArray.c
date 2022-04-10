#include <stdio.h>
int main(){
  int numOfElements,choice,val,newVal,newValIndex;
  printf("Enter number of elements\n");
    scanf("%d", &numOfElements);
      int arr[numOfElements];
    for(int i=0;i<numOfElements; i++)
    {
printf("Enter Element No.%d\n",i);
        scanf("%d", &arr[i]);

    }
  
  printf("Enter 1 to update array by value\nEnter 2 to update array by index\n");
  scanf("%d",&choice);
  if(choice==1){
  printf("Enter the value you want to change\n");
  scanf("%d",&val);
  printf("Enter the new  value\n");
  scanf("%d",&newVal);
    for(int i=0;i<10;i++){
  if(arr[i]==val){
    arr[i]=newVal;
  }
  }
  }
  else if(choice==2){
    printf("Enter the index of  value you want to change\n");
  scanf("%d",&newValIndex);
  printf("Enter the new  value\n");
  scanf("%d",&newVal);
  arr[newValIndex]=newVal;
  }
  else{
    printf("Enter Valid Choice\n");
    main();
  }
  
  printf("updated Array:\n");
  for(int i=0;i<numOfElements;i++){
  printf("%d\n",arr[i]);
  }
  return 0;
}
