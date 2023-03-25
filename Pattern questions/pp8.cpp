#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i+j-1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
}

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n){
//         int value = i;
//         int j=1;
//         while(j<=i){
//             cout<<value<<" ";
//             value++; //First value in each row=row number
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
// }



// For n=4
// 1
// 2 3
// 3 4 5
// 4 5 6 7