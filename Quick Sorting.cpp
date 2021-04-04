#include <iostream>
using namespace std;

int p(int *a,int start,int end)
{
    int pivot=a[end];
    int pi=start;
    int i,temp; 
    for(i=start;i<end;i++)
    {
    	if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[pi];
            a[pi]=temp;
            pi++;
        }
     }
    
      temp=a[end];
      a[end]=a[pi];
      a[pi]=temp;
     return pi;
 }
 
 void sort(int *a,int start,int end)
 {
    if(start<end)
    {
         int pi=p(a,start,end);
             sort(a,start,pi-1);
             sort(a,pi+1,end);
    }
}
int main()
{
    int a[10],n,i;
        cout<<"Enter the size of an array:"<<endl;
        cin>>n;
        cout<<"Enter the array elements:"<<endl;
        for(i=0;i<n;i++)
       {
    	 cin>>a[i];
       }
      sort(a,0,n-1);
      cout<<"Sorted array is:"<<endl;
      for(i=0;i<n;i++)
      {
    	 cout<<a[i]<<" ";
      }
    return 0;
}
