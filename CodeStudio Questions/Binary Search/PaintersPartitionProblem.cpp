bool isPossibleSoln(vector<int> &boards,int k,int mid)
{
    int painterCount = 1;
    int pageSum = 0;
    int len=boards.size();
    for(int i=0; i<len; i++)
    {
        if((pageSum + boards[i])<=mid) pageSum += boards[i];
        else
        {
            painterCount++;
            if(painterCount>k || boards[i]>mid) return false;
            pageSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int start=0;
    int end=0;
    int len=boards.size();
    for(int i=0;i<len;i++)
    {
        end += boards[i];
    }
    int ans=-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isPossibleSoln(boards,k,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}