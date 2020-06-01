class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int n = candies.size();
        int max_can = 0;
        for(int i=0;i<n;i++)
        {
            if(candies[i]>max_can)
            {
                max_can = candies[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=max_can)
            {
                res.push_back(true);
            }else{
                res.push_back(false);
            }
        }
        return res;
    }
};