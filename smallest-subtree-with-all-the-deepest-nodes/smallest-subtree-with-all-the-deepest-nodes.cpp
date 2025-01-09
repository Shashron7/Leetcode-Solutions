/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int h(TreeNode* root, map<int,int>& mp)
    {
        if(!root) return 0;

        int lh=h(root->left,mp);
        int rh=h(root->right,mp);

        return mp[root->val]=1+max(lh,rh);
    }

    void func(TreeNode* root, TreeNode*& ans, map<int,int>& mp)
    {
        if(!root) return ;
        int lh=0, rh=0;
        if(root->left) lh=mp[root->left->val];
        if(root->right) rh=mp[root->right->val];

        if(lh > rh)
        {
            func(root->left,ans,mp);
        }
        else if(rh > lh)
        {
            func(root->right,ans,mp);
        }
        else
        {
            ans=root;
            return ;
        }

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<int,int> mp;

        int a=h(root,mp);
        for(auto it: mp) cout<<it.first<<" "<<it.second<<endl;
        TreeNode* ans=NULL;
        func(root,ans,mp);

        return ans;
        
    }
};