class Solution {
public:
    string decodeString(string s) {

        int num=0;

        string curr="";

        stack<pair<string,int>> st;
        for(auto it: s)
        {
            if(isdigit(it))
            {
                num=num*10+(it-'0');
            }
            else if(it=='[')
            {
                st.push({curr,num});
                curr="";
                num=0;
            }
            else if(it==']')
            {
                auto last=st.top();
                st.pop();

                int rep=last.second;
                string lastS=last.first;

                string repeated="";

                for(int i=0; i<rep; i++)
                {
                    repeated+=curr;
                }

                curr=lastS+repeated;
            }
            else
            {
                curr+=it;
            }
        }


        return curr;

        //use a pair in stack to keep track of last context

        //last string and last number keep track of that
        
        
    }
};