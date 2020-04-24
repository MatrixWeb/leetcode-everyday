//归并排序
class Solution {
public:

    int mergeSort(vector<int>& nums, int l, int r, vector<int>& temp)
    {
        if(l>=r)
            return 0;
        int mid= l+(r-l)/2;
        int res = mergeSort(nums, l, mid,temp)+mergeSort(nums, mid+1,r,temp);
        int lp=l, rp=mid+1, pos=l;
        while(lp<=mid && rp<=r)
        {
            if(nums[lp]<=nums[rp])
            {
                temp[pos++]=nums[lp++];
            }else{
                res+=mid-lp+1;
                temp[pos++]=nums[rp++];
            }
        }
        for(int k=lp;k<=mid;k++)
        {
            temp[pos++]=nums[k];
        }
        for(int k=rp;k<=r;k++)
        {
            temp[pos++]=nums[k];
        }
        copy(temp.begin()+l,temp.begin()+r+1,nums.begin()+l);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n);
        return mergeSort(nums,0,n-1,temp);
    }
};