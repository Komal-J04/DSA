// #include<iostream>
// #include<vector>
// using namespace std;

// void print(vector<int>arr)
// {
//     cout<<"Merged array is ";
//     for(int i=0;i<arr.size();i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main()
// {
//     vector<int> arr1;
//     arr1.push_back(1);
//     arr1.push_back(3);
//     arr1.push_back(5);
//     arr1.push_back(7);
//     arr1.push_back(9);

//     vector<int> arr2;
//     arr2.push_back(2);
//     arr2.push_back(4);
//     arr2.push_back(6);
//     arr2.push_back(8);
//     arr2.push_back(10);

//     vector<int>arr3(10,0);

//     int i=0, j=0, k=0;
//     while(i<arr1.size() && j<arr2.size())
//     {
//         if(arr1[i]<arr2[j])
//         {
//             arr3[k]=arr1[i];
//             k++;
//             i++;
//         }
//         else if (arr1[i]>=arr2[j])
//         {
//             arr3[k]=arr2[j];
//             k++;
//             j++;
//         }
//     }
//     //Remaining elements of array 1
//     for(;i<arr1.size();i++) //while(i<arr1.size())
//     {
//         arr3[k]=arr1[i];
//         k++;
//     }
//     //Remaining elements of array 2
//     for(;j<arr2.size();j++) //whiile(j<arr2.size())
//     {
//         arr3[k]=arr2[j];
//         k++;
//     }

//     cout<<"arr3"<<endl;
//     print(arr3);

//     arr1.clear();
//     for(int p=0;p<arr3.size();p++)
//     {
//         arr1.push_back(arr3[p]);
//     }
//     cout<<"arr1"<<endl;
//     print(arr1);
// }





#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>arr)
{
    cout<<"Merged array is ";
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(3);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(9);

    vector<int> arr2;
    arr2.push_back(2);
    arr2.push_back(4);
    arr2.push_back(6);
    arr2.push_back(8);
    arr2.push_back(10);

    vector<int>arr3;

    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i]>=arr2[j])
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    //Remaining elements of array 1
    for(;i<arr1.size();i++) //while(i<arr1.size())
    {
        arr3.push_back(arr1[i]);
    }
    //Remaining elements of array 2
    for(;j<arr2.size();j++) //whiile(j<arr2.size())
    {
        arr3.push_back(arr2[j]);
    }

    cout<<"arr3"<<endl;
    print(arr3);

    arr1.clear();
    for(int p=0;p<arr3.size();p++)
    {
        arr1.push_back(arr3[p]);
    }
    cout<<"arr1"<<endl;
    print(arr1);
}