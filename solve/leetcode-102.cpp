/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty())
        {
            int n = (int)helper.size();
            vector<int> tmp;
            while(n>0)
            {
                TreeNode* curr = helper.front();
                tmp.push_back(curr->val);
                if(curr->left)
                {
                    helper.push(curr->left);
                }
                if(curr->right)
                {
                    helper.push(curr->right);
                }
                helper.pop();
                n--;
            }
            res.push_back(tmp);
        }
        return res;
    }
};