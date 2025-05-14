// #include<bits/stdc++.h>
// using namespace std;

// #define d 256
// #define q 101

// void rabinKarp(string text,string pattern){
//     int n=text.size();
//     int m=pattern.size();

//     int h=1; // d rase to m-1 mod q

//     for(int i=0;i<m-1;i++){
//         h=(h*d)%q; //rolling hash
//     }

//     int p=0;

//     int t=0;

//     for(int i=0;i<m;i++){
//      p=(d*p+pattern[i])%q; //hash of pattern
//         t=(d*t+text[i])%q; //hash of text
    

//     }

//     for(int i=0;i<=n-m;i++){
//         if(p==t){
//             bool match=true;
//             for(int j=0;j<m;j++){
//                 if(text[i+j]!=pattern[j]){
//                     match=false;
//                     break;
//                 }
//             }
        
//         if(match){
//             cout<<"Pattern found at index "<<i<<endl;
//         }


//         }

//         if(i<n-m){
//             t=(d*(t-text[i]*h)+text[i+m]) %q;

//             if(t<0){
//                 t+=q;
//             }
//         }
//     }
// }

// int main(){
//     string text;
//     string pattern;
//     cout<<"Enter the text: ";
//     cin>>text;
//     cout<<"Enter the pattern: ";
//     cin>>pattern;

//     rabinKarp(text,pattern);

//     return 0;
// }








#include<bits/stdc++.h>
using namespace std;

#define d 256
#define q 101

void rabinKarp( string text, string pattern ) {
    int n=text.size();
    int m=pattern.size();

    int h=1;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }

    int p=0;
    int t=0;

    for(int i=0;i<m;i++){
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;
    }

    for(int i=0;i<n-m;i++){
        if(p==t){
            bool match=true;
            for(int j=0;j<m;j++){
                if(text[i+j]!=pattern[j]){
                    match=false;
                    break;
                }
            }
                if(match){
                    cout<<"Pattern found at index "<<i<<endl;
                }

                if(i<n-m){
                    t=(d*(t-text[i]*h)+text[i+m])%q;

                    if(t<0){
                        t+=q;
                    }
                }

            
        }
    }

}

int main(){
    string text;
    string pattern;
    cout<<"Enter the text: ";
    cin>>text;
    cout<<"Enter the pattern: ";
    cin>>pattern;

    rabinKarp(text,pattern);

    return 0;
}