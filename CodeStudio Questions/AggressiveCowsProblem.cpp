bool isPossible(vector<int>& stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];
    int len = stalls.size();
    for(int i=0;i<len;i++)
    {
        if(stalls[i]-lastPos >= mid)
        {
            lastPos = stalls[i]; 
            cowCount++;
            if(cowCount==k) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int start = 0;
    int end = -1;
    int len = stalls.size();
    for(int i=0;i<len;i++)
    {
        end = max(end,stalls[i]);
    }
    int ans=-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isPossible(stalls,k,mid))
        {
            ans=mid;
            start = mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}