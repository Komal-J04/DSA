// bool isPossibleSoln(vector<int>&arr, int mid, int m, int n)
// {
//     int ar[m]={0};
//     int i=0;
//     while(i<n)
//     {
//         int j=0;
//         while(j<m)
//         {
//             if(arr[i]+ar[j] <= mid)
//             {
//                 ar[j] += arr[i];
//                 i++;
//             }
//             else
//             {
//                 j++;
//             }
//         }
//         if(j==m) return false;
//     }
//     return true;
// }

bool isPossibleSoln(vector<int> arr, int mid, int m, int n)
{
    int studentCount = 1;
    int pageSum=0;
    int i=0;
    while(i<n)
    {
        if (arr[i]+pageSum <= mid) pageSum += arr[i];
        else
        {
            studentCount++;
            if(studentCount>m || arr[i]>mid) return false;
            pageSum=arr[i];
        }
        i++;
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int start=0;
    int end=0;
    for (int i = 0; i < n; i++) 
    {
      end = end + arr[i];
    }

    int ans=-1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isPossibleSoln(arr,mid,m,n))
        {
            end=mid-1;
            ans=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;

}

