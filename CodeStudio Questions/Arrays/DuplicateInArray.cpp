int findDuplicate(vector<int> &arr) 
{
    // Write your code here
	for(int i=0;i<arr.size();i++){
        int x=arr[i];
        for(int j=i+1;j<arr.size();j++){
            if((x ^ arr[j])==0) return x;
        }
    }
}
