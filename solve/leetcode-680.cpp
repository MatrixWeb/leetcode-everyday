class Solution {
public:
    bool padlindrome(string& s, int i,int j)
    {
        while(i<j&&s[i]==s[j])
        {
            i++;j--;
        }
        return i>=j;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j&&s[i]==s[j])
        {
            i++;j--;
        }
        return padlindrome(s, i, j-1) || padlindrome(s, i+1, j);
    }
};