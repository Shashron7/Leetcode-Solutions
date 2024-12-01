/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
        string s="";
        void func(TreeNode* root, string& s)
        {
            if(!root) return ;
            s+=to_string(root->val)+'.';
            func(root->left,s);
            func(root->right,s);
            
            
        }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         s="";
         func(root,s);
        //  cout<<"s is "<<s;
         return s;

    }
    TreeNode* func2(vector<int>& v, int left, int right)
    {
        if (left > right) {
        return NULL; // Base case: No nodes to construct in this range
    }

        int i=left+1;
        while(i<=right && v[i] < v[left]) i++;
        // cout<<"i is "<<i<<endl;
        TreeNode* newNode= new TreeNode(v[left]);
        newNode->left= func2(v,left+1,i-1);
        newNode->right=func2(v,i,right);
        return newNode;


    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0) return NULL;
        // cout<<"data given is "<<data;
        vector<int> v;
        int i=0;
        while(i<data.size())
        {
            int start=i;
            while(i<data.size() && data[i]!='.')
            {
                i++;
            }
            // cout<<"i is "<<i<<endl;
            string curr=data.substr(start,i-start);
            int num=stoi(curr);
            v.push_back(num);
            // cout<<"curr is "<<curr<<endl;
            i++;
        }

        // for(auto it :v) cout<<it<<" ";
        return func2(v,0,v.size()-1);

        // return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;