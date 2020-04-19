//找出循环节
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1==0)
            return 0;
        int s1cnt=0,s2cnt=0;
        int index=0;
        unordered_map<int ,pair<int,int>> recall;
        pair<int ,int> pre,in_loop;
        while(1)
        {
            s1cnt++;
            for(char c1:s1)
            { 
                if(c1==s2[index])
                {
                    index++;
                    if(index==s2.size())
                    {
                        index=0;
                        s2cnt++;
                    }
                }
            }
            if(s1cnt==n1)
            {
                return s2cnt/n2;
            }
            if(recall.count(index))
            {
                pre = recall[index];
                in_loop.first = s1cnt - (pre.first);
                in_loop.second = s2cnt-(pre.second);
                break;
            }else{
                recall[index]={s1cnt,s2cnt};
            }
        }
        int ans = pre.second+(n1-pre.first)/in_loop.first*in_loop.second;
        int rest = (n1-pre.first)%in_loop.first;
        for(int i=0;i<rest;i++)
        {
            for(char ch:s1)
            {
                if(ch == s2[index])
                {
                    index++;
                    if(index == s2.size())
                    {
                        ans++;
                        index=0;
                    }
                }
            }
        }
        return ans/n2;
    }
};