/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
   
   void func(Node* node, unordered_set<Node*>& vis, unordered_map<Node*, Node*>& mp)
   {
        if(!node) return;

        vis.insert(node);
        Node* curr= new Node(node->val);
        mp[node]=curr;

        for(auto it: node->neighbors)
        {
            if(vis.find(it)==vis.end())
            {
                func(it,vis,mp);
            }
        }


        

        
   }

   void f(Node*& node, unordered_set<Node*>& vis, unordered_map<Node*,Node*>& mp)
   {
        if(!node) return ;

        vis.insert(node);
        Node* currNode=mp[node];
        for(auto it: node->neighbors)
        {
            currNode->neighbors.push_back(mp[it]);
            
        }

        for(auto it: node->neighbors)
        {
            if(vis.find(it)==vis.end()) f(it,vis,mp);
        }

   }
    Node* cloneGraph(Node* node) {
        unordered_set<Node*> vis;

        unordered_map<Node*, Node*> mp;
        func(node,vis,mp);

        vis.clear();

        f(node,vis,mp);
        return mp[node]; 


    }
};