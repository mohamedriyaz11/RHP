class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l+1<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        return nums[l]==target?l:nums[r]==target?r:-1;
    }
};