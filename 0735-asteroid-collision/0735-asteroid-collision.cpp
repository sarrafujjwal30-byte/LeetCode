class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++)
            {
                 
                if(asteroids[i]<0)
                    {
                        while(!st.empty() && st.top()>0 && st.top()<-asteroids[i] )
                        st.pop();
                    
                if (!st.empty() && st.top() > 0 && st.top() == -asteroids[i])
                    {
                    st.pop();
                    continue;
                    }
                if(!st.empty() && st.top()>=(asteroids[i]*-1))
                            continue;
                    }
                    
                st.push(asteroids[i]);
            }
    
            vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--)
            {
                ans[i]=st.top();
                st.pop();
            }
        return ans;
    }
};