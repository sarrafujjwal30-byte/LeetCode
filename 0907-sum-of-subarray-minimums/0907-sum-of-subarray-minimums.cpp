class Solution {
public:
    vector<int> findnse(vector<int>arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                    st.pop();
                nse[i]=st.empty()?n:st.top();
                st.push(i);
            }
        return nse;
    }
    vector<int> findpsee(vector<int>arr){
        int n=arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++)
            {
                while(!st.empty() && arr[st.top()]>arr[i])
                    st.pop();
                psee[i]=st.empty()?-1:st.top();
                st.push(i);
            }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int left, right;
        int n=arr.size();
        int mod=1e9+7;
        long long total=0;
        vector<int> nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        for(int i=0;i<n;i++)
            {
                left=i-psee[i];
                right=nse[i]-i;
                total=(total+(1LL*left*right*arr[i])%mod)%mod;
            }
        return total;
        
    }
};