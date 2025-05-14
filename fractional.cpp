#include<bits/stdc++.h>

#include<ctime>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(Item a,Item b){
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;

}
double fractionalKnapsack(int W,vector<Item> items){
    sort(items.begin(),items.end(),cmp);
    double finalvalue=0.0;

    for(Item i: items){
        if(W==0){
            break;
        }
        if(i.weight<=W){
            W-=i.weight;
            finalvalue+=i.value;
        }
        else{
            finalvalue+=i.value*((double)W/i.weight);
            // If the weight of the item is more than the remaining capacity,
            

          
            W=0;

        }

    }

    return finalvalue;
    
}

int main(){
    int W ;
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack: ";
    cin>>W;

    
   

    vector<Item> items(n);
    cout<<"Enter the value and weight of each item: ";

    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;

    }
 clock_t start = clock();
     cout<<"Maximum value in Knapsack = "<<fractionalKnapsack(W,items)<<endl;
    

    clock_t end = clock();
    cout<<"Time taken"<<(double)(end/start)/CLOCKS_PER_SEC<<" seconds"<<endl;

    return 0;
}
// #include<bits/stdc++.h>

// using namespace std;

// struct Item{
//     int value;
//     int weight;
// };


// bool cmp(Item a,Item b){
//     double r1=(double)a.value/a.weight;
//     double r2=(double)b.value/b.weight;
//     return r1>r2;
// }

// double fractionalKnapsack(int W,vector<Item> items){
//     sort(items.begin(),items.end(),cmp);
//     double totalValue=0.0;

//     for (Item i:items){
//         if(W==0){
//             break;
//         }
//         if(i.weight<=W){
//             W-=i.weight;
//             totalValue+=i.value;

//         }
//         else{
//             totalValue+=i.value*((double)W/i.weight);
           
//             // If the weight of the item is more than the remaining capacity,
//             // take the fraction of the item that fits in the knapsack

//             W=0;
//         }
//     }
//     return totalValue;
// }

// int main(){
//     int n;
//     int w;
//     cout<<"Enter number";
//     cin>>n;
//     cout<<"capoacity";
//     cin>>w;

//     vector<Item> items(n);
//     cout<<"Enter value and weight of each item: ";
//     for(int i=0;i<n;i++){
//       cin>>items[i].value;
//       cin>>items[i].weight;
//     }
//     cout<<"Bhai maxium value"<<fractionalKnapsack(w,items)<<endl;
//     return 0;
// }