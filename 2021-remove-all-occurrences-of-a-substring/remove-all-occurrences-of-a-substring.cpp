class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        stack<char> st;

        char End=part[part.size()-1];
        int n=part.size();

        string rev=part;
        reverse(rev.begin(), rev.end());
        for(int i=0; i<s.size(); i++)
        {
            if( st.size() >= n && st.top() == End)
            {
                int size = n;
                string curr="";
                while(size--)
                {
                    curr+=st.top();
                    st.pop();
                }
                reverse(curr.begin(), curr.end());

                // If the current string does not match `part`, push it back to the stack
                if (curr != part) {
                    for (char ch : curr) {
                        st.push(ch);
                    }
                }
            }
            cout<<"curr ind is "<<s[i];
            st.push(s[i]);
            
        }

         if( st.size() >= n && st.top() == End)
            {
                int size = n;
                string curr="";
                while(size--)
                {
                    curr+=st.top();
                    st.pop();
                }
                reverse(curr.begin(), curr.end());

                // If the current string does not match `part`, push it back to the stack
                if (curr != part) {
                    for (char ch : curr) {
                        st.push(ch);
                    }
                }
            }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    
    }
};