class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto it: tokens)
        {
            if(it=="+")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                int r=f+s;
                st.push(r);
            }
            else if(it=="-")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                int r=s-f;
                st.push(r);
            }
            else if(it=="/")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                int r=s/f;
                st.push(r);
            }
            else if(it=="*")
            {
                int f=st.top();
                st.pop();
                int s=st.top();
                st.pop();
                int r=s*f;
                st.push(r);
            }
            else
            {
                int num=stoi(it);
                st.push(num);
            }
        }

        return st.top();
    }
};