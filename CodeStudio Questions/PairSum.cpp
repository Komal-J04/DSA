#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   int i=0;
   while(i<arr.size()){
      int x=arr[i];
      int j=i+1;
      while(j<arr.size()){
         if((x+arr[j])==s){
            ans.push_back({x,arr[j]});
         }
         j++;
      }
      i++;
   }
   return ans;
}