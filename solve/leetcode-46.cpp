//回溯
class Solution {
public:
    void backtrack(vector<vector<int> >& res, vector<int>& nums, int first, int len)
    {
        if(first == len)
        {
            res.push_back(nums);
            return;
        }
        for(int i=first;i<len;i++)
        {
            swap(nums[i], nums[first]);
            backtrack(res, nums, first+1,len);
            swap(nums[i],nums[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res,nums,0,(int)nums.size());
        return res;
    }
};