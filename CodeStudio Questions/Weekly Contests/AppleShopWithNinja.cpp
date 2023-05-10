long long appleAndCoupon(int n, int m, vector<int> arr){
    // Write your code here.
    long long minCoins = 0;
    long long dupTotalCoins = 0;
    for(int i=0;i<n;i++)
    {
        dupTotalCoins += arr[i];
    }
    for(int i=0;i<m;i++)
    {
        int maxCoins = arr[0];
        for(int j = 0 ; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
    int k = 0;
    int i = n-1;
    while(i>=0)
    {
        k++;
        if (k == m) {
          dupTotalCoins -= arr[n - m];
          break;
        } else
          i--;
    }
    return dupTotalCoins;
}