#include<iostream>
#include<vector>
using namespace std;

//NOT AN IN-PLACE SORT
void moveZeroes(vector<int>& nums) 
{
        int n=nums.size();
        vector<int>arr;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                arr.push_back(nums[i]);
            }
            else count++;
        }

        int k=arr.size();
        for(int i=k;i<n;i++)
        {
            arr.push_back(0);
        }

        nums.clear();
        for(int p=0;p<n;p++)
        {
            nums.push_back(arr[p]);
        }       
}


//IN PLACE SORT
void moveZeroes(vector<int>& nums) 
{
    int i=0,j=0;
    int n=nums.size();
    // while(j<n)
    // {
    //     if(nums[j]==0) j++;
    //     else
    //     {
    //         swap(nums[i],nums[j]);
    //         i++;
    //         j++;
    //     }
    // }

    //shifting all non-zero values to left
    for(;j<n;j++)
    {
        if(nums[j]!=0)
        {
            swap(nums[i],nums[j]);
            i++;
        }
    }
}