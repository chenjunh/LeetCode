#169. Majority Element
#=======================Idea======================
#Since the majority element always exists in the array,
#we can discard the first part of the array when this subarray 
#has half number of elements equal to the starting element, 
#and find out the majority element of the rest part of the array.
#e.g. {a,b,a,b,a,b,a}
#as we loop to the second index, we can discard {a,b} and focus on {a,b,a,b,a}.
#So on so forth, we discard two more subarrays {a,b} and finally get the majority element a
# of the last part of the array {a}, which is also the majority element of the whole array.
#e.g. {a,a,a,b,b,b,a}
#as we loop to the sixth index, we can discard {a,a,a,b,b,b} and focus on {a}.

#Note: the operation above is only valid when we know the majority element exists in the array.
#=======================Idea======================
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int x=nums[0];
        for (int i=0;i<n;i++){
            if (nums[i]==x) count++;
            else count--;
            if (count==0) x=nums[i+1];#when count=0, the first part of array has half number of elements equal the starting element of this subarray. So we set x to be the next element, which is the starting element of the remaining subarray.
        }
        return x;
    }
};
