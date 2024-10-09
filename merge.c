#include<stdio.h>
int main()
{
int arr1[100],arr2[100],arr3[100];
int s1,s2,s3,temp;
int i,j;
printf("enter the size of first array:");
scanf("%d",&s1);
printf("enter the elements of first array:");
for(i=0;i<s1;i++)
{
scanf("%d",&arr1[i]);
}
printf("enter the size of 2nd array:");
scanf("%d",&s2);
printf("enter the elements of 2nd array:");
for(i=0;i<s2;i++)
{
scanf("%d",&arr2[i]);
}
s3=s1+s2;
for(i=0;i<s1;i++)
{
arr3[i]=arr1[i];
}
for(j=0;j<s2;j++)
{
arr3[i]=arr2[j];
i++;
}
for(i=0;i<s3-1;i++)
{
for(j=i+1;j<s3;j++)
{
if(arr3[i]>arr3[j])
{
temp=arr3[i];
arr3[i]=arr3[j];
arr3[j]=temp;
}
}
}
printf("sorted array:\n");
for(i=0;i<s3;i++)
{
printf("%d \n",arr3[i]);
}
return 0;
}

