class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=locked.size();
        if(n%2!=0) return false;
        if(n==1) return false;
        // if((s[n-1]=='(' && locked[n-1]=='1') || (s[0]==')' && locked[0]=='1')) return false;

        int unl=0; //unlocked
        int ll=0; //locked left
        for(int i=0; i<n; i++)
        {
            if(locked[i]=='0')
            {
                unl++;
            }
            else
            {
                if(s[i]==')')
                {
                    if(ll>0)
                    {
                        ll--;
                        continue;
                    }
                    else if(ll==0 && unl>0)
                    {
                        unl--;
                        continue;
                    }
                    else return false;
                }
                else ll++;
            }
        }


        int lr=0; //locked right
        unl=0;

        for(int i=n-1; i>=0; i--)
        {
            if(locked[i]=='0') unl++;
            else
            {
                if(s[i]=='(')
                {
                    if(lr > 0) 
                    {
                        lr--;
                        continue;
                    }
                    else if(lr==0 && unl>0)
                    {
                        unl--;
                        continue;
                    }
                    else return false;
                }
                else lr++;
            }
        }



        return true;
    }
};