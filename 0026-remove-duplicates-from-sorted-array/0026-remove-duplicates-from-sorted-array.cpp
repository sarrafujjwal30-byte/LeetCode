class Solution {
public:
   int removeDuplicates(vector<int>& arr) {
    int n=arr.size();
    int l=0;
    int r=1;
    while(r<n)
    {
        if(arr[l]!=arr[r])
        {
            arr[l+1]=arr[r];
            l++;
            r++;
        }
        else
        r++;
    }
return l+1;
    }
};
    
