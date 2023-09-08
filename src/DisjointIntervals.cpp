#915. Partition Array into Disjoint Intervals
#=================Idea================= 
#We just need to find out the biggest element in the "left" array(maxL) and 
#the smallest element in the "right" array(minR). 
#Criteria: maxL <= minR
#=================Idea=================
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> minR(n,0);#minR[x] means smallest element among the subarray [x,x+1,...,end]
        minR[n-1]=nums[n-1];
        for (int i=n-2;i>0;i--){
            minR[i]=min(minR[i+1],nums[i]);
        }
        int maxL=nums[0];
        int length=0;
        for (int i=0;i<n-1;i++){
            length++;
            maxL=max(maxL,nums[i]);
            if (maxL<=minR[i+1]) return length;    
        }
        return -1;
    }
};
