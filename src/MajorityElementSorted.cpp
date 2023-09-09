//1150. Check If a Number Is Majority Element in a Sorted Array
//======================Idea==================
//Use binary search since the array is sorted.
//find out the first occurrence index i of the target
//then check whether nums[i+n/2] is still the target
//Note that i<=n/2, otherwise, the target can't be the majority element.
//Also note that if i=n/2 for the array with even number of elements, the target isn't the majority element.
//======================Idea==================
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n=nums.size();
        int min_idx=0;
        int max_idx=n/2;
        int cur_idx=(min_idx+max_idx)/2;
        if (nums[n/2]!=target) return false; 
        if (nums[0]!=target) 
        {
            while (cur_idx>min_idx){
                if (nums[cur_idx]==target) {
                    max_idx=cur_idx;
                    cur_idx=(min_idx+max_idx)/2;    
                }
                else {
                    min_idx=cur_idx;
                    cur_idx=(min_idx+max_idx)/2;
                }
            }
            if (nums[min_idx]==target) return nums[min_idx+n/2]==target;
            else if (max_idx==n/2 && n%2==0) return false;
            else return nums[max_idx+n/2]==target;
        }
        
        return true;
        
        

    }
};
