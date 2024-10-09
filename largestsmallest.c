#include<stdio.h>
int main(){
int n,i;
int arr[100];
int largest,smallest;
printf("Enter the no.of elements in the array:");
scanf("%d",&n);
printf("Enter the elements of array:\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
largest=smallest=arr[0];
for(i=1;i<n;i++)
{
if(arr[i]>largest){
largest=arr[i];
}
if(arr[i]<smallest){
smallest=arr[i];
}}
printf("Largest element is : %d\n",largest);
printf("Smallest element is : %d\n",smallest);
return 0;
}

