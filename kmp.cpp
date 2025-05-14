#include<bits/stdc++.h>
using namespace std;

vector <int> buildlps(string p){
    int n=p.length();
    vector<int> lps(n,0);
    int len=0;

    for(int i=1;i<n;){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
    

}


void KMP(string t,string p){
    int n=t.length();
    int m=p.length();
    vector<int> lps=buildlps(p);
    int i=0;
    int j=0;
    while(i<n){
        if(p[i]==t[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];

        }
        else if(i< n && t[i]!=p[j]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}


int main(){
    string t;
    string p;
    cout<<"Enter the text: ";
    cin>>t;
    cout<<"Enter the pattern: ";
    cin>>p;
    clock_t start=clock();
    cout<<"Time taken: "<<(double)(clock()-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
    cout<<"Bhai pattern found at index: ";
    KMP(t,p);
    
    clock_t end=clock();
    return 0;

}