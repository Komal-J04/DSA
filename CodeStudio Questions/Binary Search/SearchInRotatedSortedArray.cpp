//Solution 1

int Pivot(vector<int>& arr,int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]>=arr[0]) start=mid+1;
        else end=mid;
    }
    return start;
}

int binSearch(vector<int>arr,int start,int end,int k)
{
    while(start<=end)
    {
        int mid=start + (end-start)/2;
        if(arr[mid]==k) return mid;
        else if (k<arr[mid]) end=mid-1;
        else start=mid+1;
    }
    return -1;
}



int findPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int x=Pivot(arr, n);
    if (( k >= arr[x])&&( k <= arr[n-1])) return binSearch(arr, x, n-1, k);
    return binSearch(arr, 0, x-1, k);
}


//Solution 2  (TLE)

int Pivot(vector<int>& arr,int n)
{
    int start=0;
    int end=n-1;
    while(start<end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]>=arr[0]) start=mid+1;
        else end=mid;
    }
    return start;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int p=Pivot(arr, n);
    int start=0;
    int end=n-1;
    int mid=0;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(k==arr[mid]) return mid;
        else if(k>arr[mid])
        {
            if(k>arr[0])
            {
                start=mid;
                end=p-1;
            }
            else
            {
                start=mid+1;
            }
        }
        else
        {
            if(k>arr[0])
            {
                end=mid-1;
            } else {
              start = p;
            }
        }
    }
    return -1;
}

