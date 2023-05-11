#include<iostream>
#include<array> //STL wale array keliye include array library
using namespace std;

int main()
{
    int arr[3] = {1,2,3};

    array<int,4> a = {1,2,3,4};

    int size = a.size();
    for(int i=0;i<size;i++)
    {
        cout<<"Element at "<<i<<"th index = "<<a.at(i)<<endl;
    }
    cout<<"Empty or not - "<<a.empty()<<endl;

    array<float,0> temp;
    cout<<"Empty or not - "<<temp.empty()<<endl;

    cout<<"First element - "<<a.front()<<endl;
    cout<<"Last element - "<<a.back()<<endl;

}