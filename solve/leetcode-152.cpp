class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =(int) nums.size();
        int ans = nums[0];
        int max_f = nums[0];
        int min_f = nums[0];
        for(int i=1;i<n;i++)
        {
            int mx = max_f,mn=min_f;
            max_f = max(mx*nums[i], max(mn*nums[i], nums[i]));
            min_f = min(mx*nums[i], min(mn*nums[i], nums[i]));
            ans = max(ans, max_f);
        }
        return ans;
    }
};