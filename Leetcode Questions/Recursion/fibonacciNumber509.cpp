//using recursion

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-1) + fib(n-2);
    }
};





//using for loop
class Solution {
public:
    int fib(int n) {
        vector<int> series;
        series.push_back(0);
        series.push_back(1);

        for(int i=2;i<=n;i++)
        {
            series.push_back(series[i-1]+series[i-2]);
        }

        return series[n];
    }
}; 