#include<iostream>
using namespace std;

void reverse(int arr[],int size){
    int arrReverse[100];
    for(int i=0;i<size;i++){
        arrReverse[size-1-i]=arr[i];

        // swapping the 1st and last, 2nd and 2nd last.... values
        // int temp=arr[size-1-i];
        // arr[size-1-i]=arr[i];
        // arr[i]=temp;
    }
    for(int i=0;i<size;i++){
        cout<<arrReverse[i]<<" "; //cout<<arr[i]
    }

    //ANOTHER SOLUTION :- 2 variables start=0 end=n-1....swap(predefined function) and start++ end--
}

int main(){
    int size;
    cin>>size;

    int arr[100];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    reverse(arr,size);

}