#include<stdio.h>

#define MAX 100

int subset[MAX];
int count=0;

void subsetSum(int arr[],int n,int index,int target,int sum,int pos){
    if(sum==target){
        printf("Subset %d: ", ++count);
        for(int i=0;i<pos;i++){
            printf("%d",subset[i]);
            printf(" \n");
            return;
        }

    }

    for(int i=index;i<n;i++){
        if(sum+arr[i]<=target){
            subset[pos]=arr[i];
            subsetSum(arr,n,i+1,target,sum+arr[i],pos+1);
        }
    }
}

int main(){
     int arr[MAX];
     int n;
    
    int target;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the target sum: ");
    scanf("%d",&target);
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Subsets with sum %d:\n",target);
    subsetSum(arr,n,0,target,0,0);
    return 0;
}
    
   
   
