#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<ctime>

using namespace std;

int dp[100][100];

int matrixDP(int *p,int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
        
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],matrixDP(p,i,k)+matrixDP(p,k+1,j)+p[i-1]*p[k]*p[j]);
    }
    return dp[i][j];


    //k is partition
    //i to k and k+1 to j


}


int matrixMult(int *p,int n){
    int i=1;
    int j=n-1;
    return matrixDP(p,i,j);
}

int main(){
    int n;
    cout<<"Enter the number of matrices: ";
    cin>>n;

    int arr[n + 1];
    cout<<"Enter the dimensions of the matrices: ";
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }

    memset(dp,-1,sizeof(dp));

    clock_t start = clock();
    int result = matrixMult(arr,n+1);
    clock_t end = clock();
cout<<"Minimum number of multiplications is: "<<matrixMult(arr,n+1)<<endl;

cout<<"Time taken: "<<(double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    cout<<"bhai minkmium" <<result<<endl;

    return 0;
}




// #include<iostream>
// #include<vector>
// #include<climits>
// #include<cstring>

// using namespace std;


// int dp[100][100];

// int matrixDP(int *p,int i,int j){
// if(i==j){
// return 0;
// }
// if(dp[i][j]!=-1){
// return -1;
// }
// dp[i][j]=INT_MAX;
// for(int k=i;k<j;k++){
// dp[i][j]= min(dp[i][j],matrixDP(p,i,k)+matrixDP(p,k+1,j)+p[i-1]*p[k]*p[j]);

// }
// return dp[i][j];

// }


// int matrixMul(int *p,int n){
// int i=1;
// int j=n-1;
// return matrixDP(p,i,j);
// }


// int main(){
// int n;
// cout<<"Daldo";
// cin>>n;

// int arr[n+1];
// cout<<"dimesion dedo";
// for(int i=0;i<=n;i++){
// cin>>arr[i];
// }

// memset(dp,-1,sizeof dp);
// cout<<"bhai minkmium" <<matrixMul(arr,n+1)<<endl;
// return 0;

// }