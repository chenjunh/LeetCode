//163. Missing Ranges
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> output;
        vector<int> range(2);
        range[0]=lower;
        range[1]=upper; 
        
        int n=nums.size();
        if (n==0) {
            output.push_back(range);
            return output;
        }

        if (nums[0]>lower) {
            range[0]=lower;
            range[1]=nums[0]-1;
            output.push_back(range);
        }
        for (int i=1;i<n;i++){
            if (nums[i]-nums[i-1]>1) {
                range[0]=nums[i-1]+1;
                range[1]=nums[i]-1;
                output.push_back(range); 
            }
        }
        if (nums[n-1]<upper) {
            range[0]=nums[n-1]+1;
            range[1]=upper;
            output.push_back(range); 
        }
        return output;
    }
};
