class Solution {
public:
    int squareNum(int n)
    {
        int sum=0;
        while(n)
        {
            int q=n%10;
            sum+=q*q;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> num_set;
        while(1)
        {
            if(n==1)
                return true;
            else if(num_set.find(n)!=num_set.end())
            {
                return false;
            }
            num_set.insert(n);
            n= squareNum(n);
        }
        return false;
    }
};