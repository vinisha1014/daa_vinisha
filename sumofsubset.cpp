#include<bits/stdc++.h>

using namespace std;

int sumOfSubset(int arr[],int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(arr[n-1]>sum){
        return sumOfSubset(arr,n-1,sum);
    }
    return sumOfSubset(arr,n-1,sum) || sumOfSubset(arr,n-1,sum-arr[n-1]);
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    
    if(sumOfSubset(arr,n,sum)){
        cout<<"Subset with given sum exists"<<endl;
    }
    else{
        cout<<"Subset with given sum does not exist"<<endl;
    }
    
    return 0;
}