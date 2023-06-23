int binarySearch(vector<int>& nums, int start, int end, int elt)
{
    if(start>end) return -1;

    int mid = (start + end )/2;

    if(nums[mid]==elt) return mid;
    if(nums[mid]>elt) return binarySearch(nums,start,mid-1,elt);
    if(nums[mid]<elt) return  binarySearch(nums,mid+1,end,elt);
}

int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size()-1,target);
}