class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        
        //if I have to take bi before ai 
        //bi->ai

        //Topological sort

        //outline:
        //  I’ll first compute the in-degrees by iterating through the edges. 
        //Then, I’ll add all nodes with in-degree zero to a queue. While the queue isn’t empty, I’ll process each node and update the in-degrees of its neighbors, adding new zero in-degree nodes to the queue.


        int n=numCourses;

        queue<int> q; //queue nodes which have indegree as 0
        vector<int> ans; //answer 
        vector<int> indegree(n,0); //indegree

        vector<int> adj[n];
        for(auto it : prereq)
        {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]); 
        }

        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            auto node=q.front(); //taking out the top node
            q.pop(); //popping

            ans.push_back(node);
            for(auto it: adj[node]) //iterating through the neighbors
            {
                if(--indegree[it]==0) //checking if the neighbors have indegree as 0 now so adding them into the queue
                {
                    q.push(it); 
                }
            }
        }

        if(ans.size()==n) return ans; //cycle we cant create an order... DAG Directed Acyclic Graphs 
        

        return {}; //means its impossible/cycle present
    }
};