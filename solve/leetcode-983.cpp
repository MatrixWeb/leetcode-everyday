class Solution {
    unordered_set<int> day_sets;
    vector<int> costs;
    int mem[366]={0};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->costs = costs;
        for(auto d:days)
        {
            day_sets.insert(d);
        }
        memset(mem,  -1 , sizeof(mem));
        return dp(1);
    }
    int dp(int i)
    {
        if(i>365)
            return 0;
        if(mem[i]!=-1)
            return mem[i];
        if(day_sets.count(i)!=0)
        {
            mem[i] = min(min(costs[0]+dp(i+1), costs[1]+dp(i+7)), costs[2]+dp(i+30));
        }else
        {
            mem[i]=dp(i+1);
        }
        return mem[i];
    }
};