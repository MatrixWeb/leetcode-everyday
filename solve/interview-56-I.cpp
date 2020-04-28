//分组异或
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum=0;
        for(auto num:nums)
        {
            sum=sum^num;
        }
        int pos=0;
        while((sum&1)==0)
        {
            pos++;
            sum=sum>>1;
        }
        int res_a=0;
        int res_b=0;
        int tmp = 1<<pos;
        for(auto num:nums)
        {
            if(num&tmp)
            {
                res_a=res_a^num;
            }else{
                res_b=res_b^num;
            }
        }
        vector<int> res;
        res.push_back(res_a);
        res.push_back(res_b);
        return res;
    }
};