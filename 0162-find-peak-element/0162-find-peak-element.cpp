class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low =0;
        int high=nums.size()-1;
        int mid;
        while(low<high)
        {
            mid=low+(high-low)/2;
             if (nums[mid] > nums[mid + 1]) { 
                // Peak lies to the left (including mid)
                high = mid;
            } else {
                // Peak lies to the right
                low = mid + 1;
            }
        }
        return low; 

        }

    };
