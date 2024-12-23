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
    int func(vector<int>& v)
    {
        vector<int> copy=v;
        sort(copy.begin(), copy.end());

        map<int,int> mp1, mp2;
        for(int i=0; i<copy.size();i++)
        {
            mp1[copy[i]]=i;
            mp2[v[i]]=i;
        }
        int ans=0;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]!=copy[i])
            {
                int val=v[i];
                v[i]=copy[i];
                v[mp2[copy[i]]]=val;
                mp2[val]=mp2[copy[i]];
                ans++;


                
            }
            
        }
        
        
        return ans;
        
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                
            }

           ans+=func(v);
            cout<<endl;
        }
        return ans;
    }
};