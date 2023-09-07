#Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#You may assume that each input would have exactly one solution, and you may not use the same element twice.

#You can return the answer in any order.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map < int, int > hmp;#create hash map with <key, val> = <int,int>, in our case, key is the number and val is the corresponding index, i.e. key=nums[val];
        int n=nums.size();#length of the vector "nums"
        vector<int> output(2,0);#output vector storing two indices of the vector "nums"
        for (int i=0;i<n;i++){
            int R=target-nums[i];
            if (hmp.contains(R)){#check if the other number exists in the hashmap
                output[0]=i;
                output[1]=hmp[R];
                return output;
            }
            hmp.insert({nums[i],i});#insert the pair <nums[i],i> into hashmap so that it could be found later
        }
        return {-1,-1};
    }
};
