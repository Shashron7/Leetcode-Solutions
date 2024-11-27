class Solution {
public:
    void disp(vector<vector<char>>& mat)
    {
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    void func(int stones, int i, int j, vector<vector<char>>& mat, int m, int n)
    {
        if(j<0) return ;
        int newcolumn=m-1-i;
        for(int x=j-stones+1; x<=j; x++)
        {
           mat[x][newcolumn]='#';
        }
        // disp(mat);
        
        return ;

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();

        vector<vector<char>> mat(n, vector<char>(m,'.'));
        // disp(mat);

        for(int i=0; i<m; i++)
        {
            int stones=0;
            for(int j=0; j<n; j++)
            {
                if(box[i][j]=='#')
                {
                    stones++;
                    // cout<<"stones are "<<stones<<endl;

                }
                else if(box[i][j]=='*')
                {
                    if(stones)
                    {
                        // cout<<"entering";
                        func(stones,i,j-1,mat,m,n);
                        
                        
                    }
                    mat[j][m-1-i]='*';
                    stones=0;
                    
                }

                if(j==n-1)
                {
                    if(stones)
                    {
                        // cout<<"entering last option";
                        func(stones,i,j,mat,m,n);
                    }
                }
            }
        }

        return mat;
    }
};