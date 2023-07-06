#include<iostream>
using namespace std;
int binarySearch(int [],int,int);
int main()
{
  int arr[5]={1,2,3,4,5};
  int r;
  r=binarySearch(arr,5,6);
  printf("%d",r);
}
int binarySearch(int arr[], int n, int k)
{
   int l=0,u=n-1,m;
   while(l<=u)
   {
    m=(l+u)/2;
    if(k==arr[m])
     return m;
    else if(k>arr[m])
     l=m+1;
     else if(k<arr[m])
      u=m-1;
   }
   return -1;
}