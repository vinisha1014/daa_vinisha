#include<bits/stdc++.h>

using namespace std;

vector <int> buildLPS(string p){

    int n=p.size();

    vector <int> lps(n,0);

    int len=0;

    for(int i=1;i<n;){
        //aabbcc
        //01
        if(p[i]==p[len]){
             len++;
        lps[i]=len;
        i++;

        }
       
    
    else{
        if(len!=0){
            //aabbcc
            //adba
            
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

    //text
    //pattern
    int n=t.size();
    int m=p.size();

    vector <int> lps=buildLPS(p);

    int i=0; //text
    int j=0;    //pattern

    while(i<n){
        if(t[i]==p[j]){
        //aabbcc
        //adba
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<n && t[i]!=p[j]){
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

    KMP(t,p);

    return 0;
}