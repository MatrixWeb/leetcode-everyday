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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty())
        {
            int s = myQueue.size();
            while(s>0)
            {
                TreeNode* cur = myQueue.front();
                myQueue.pop();
                if(cur->left)
                    myQueue.push(cur->left);
                if(cur->right)
                    myQueue.push(cur->right);
                s--;
                if(s==0)
                {
                    res.push_back(cur->val);
                }
            }
        }
        return res;

    }
};