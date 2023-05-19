class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //Storing the values in a temporary array in a sorted manner and findind the last element(highest value) and then searching for that element in the original array


        // vector<int> vect2; 
        // for (int i=0; i<arr.size(); i++) 
        //     vect2.push_back(arr[i]); 
        // sort(vect2.begin(),vect2.end());
        // int x=vect2[vect2.size()-1];
        // for(int i=0;i<arr.size();i++)
        // {
        //     if(arr[i]==x) return i;
        // }
        // return 0;





        //Case 1: arr[mid]<arr[mid+1] (rising edge) then start=mid+1 else end=mid (not mid-1 because the mid element might also be the peak value)


        // int size=arr.size();
        // int start=0;
        // int end=size-1;
        // int ans=0;
        // int mid=(start+end)/2;
        // while(start<end)
        // {
        //     if(arr[mid]<arr[mid+1]) start = mid+1;
        //     else end=mid;
        //     mid=(start+end)/2;
        // }
        // return start;





        //3 Cases : arr[mid]<arr[mid+1]  OR  arr[mid]<arr[mid-1]  OR  mid is peak


        // int size=arr.size();
        // int start=0;
        // int end=size-1;
        // int ans=0;
        // int mid=(start+end)/2;
        // while(start<end)
        // {
        //     if(arr[mid]<arr[mid+1]) start = mid+1;
        //     else if(arr[mid]<arr[mid-1]) end=mid-1;
        //     else return mid;
        //     mid=(start+end)/2;
        // }
        // return 0;
    }
};