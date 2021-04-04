#include<iostream>
using namespace std;

int main(){
    int a[10],n,j,i,temp;
    cout<<"Enter the size of an array: ";
    cin>>n;
    cout<<"Enter the Elements"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Entered elements is:"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    cout<<"Sorted array is:"<<endl;
    for(i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
    return 0;
}
