class Solution {
public:
    string getDigits(string &s ,size_t& ptr)
    {
        string t="";
        while(isdigit(s[ptr]))
        {
            t.push_back(s[ptr++]);
        }
        return t;
    }
    string getString(vector<string>& s)
    {
        string t="";
        for(auto &e:s)
        {
            t=t+e;
        }
        return t;
    }
    string decodeString(string s) {
        vector<string> stk;
        size_t ptr = 0;
        while(ptr < s.size())
        {
            char cur = s[ptr];
            if(isdigit(cur))
            {
                string digit = getDigits(s, ptr);
                stk.push_back(digit);
            }else if(isalpha(cur)||cur=='[')
            {
                stk.push_back(string(1,s[ptr++]));
            }else{
                ptr++;
                vector<string> sub;
                while(stk.back()!="[")
                {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(),sub.end());
                stk.pop_back();
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t,o=getString(sub);
                while(repTime--){
                    t=t+o;
                }
                stk.push_back(t);
            }
        }
        return getString(stk);
            
    }
};