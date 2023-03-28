#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p=0;
    switch(100){ //stands for always true
        case 100 : 
             p = n /100;
             n = n - (p*100);
             cout<<"No. of 100 notes="<<p<<endl;
        case 50:
                p=0;
                p = n / 50;
                n = n - (p*50);
                cout<<"No. of 50 notes="<<p<<endl;
        case 20:
                p=0;
                p = n / 20 ;
                n = n - (p*20);
                cout<<"No. of 20 notes="<<p<<endl;
        case 1:
                cout<<"No. of 1 notes="<<n<<endl;
    }
}