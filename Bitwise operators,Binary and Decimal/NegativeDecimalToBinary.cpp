#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p=n;
    n=-n;
    int ans=0,i=0;
    while(p!=0){
        int bit=n&1;
        p=p>>1;
        ans=(bit*pow(10,i))+ans;
        i++;
    }
    ans=~(ans);
    cout<<ans;
}
//galat h