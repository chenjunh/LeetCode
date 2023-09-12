//2404. Most Frequent Even Element
//=====================Idea==================
//Hash map to store <nums[i],freq>
//Then pick out the most frequent and smallest even number
//=====================Idea==================
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> hmp;
        int n=nums.size();
        int maxelem=pow(10,5);
        int freq=1;
        int existeven=0;
        for (int i=0;i<n;i++){
            if (!hmp.contains(nums[i])) hmp.insert({nums[i],1});
            else hmp[nums[i]]++;

            if (nums[i]%2==0) {
                existeven=1;
                if (freq==hmp[nums[i]] && maxelem>nums[i])
                    maxelem=nums[i];
                else if (freq<hmp[nums[i]]) {
                    freq=hmp[nums[i]];
                    maxelem=nums[i];
                }
            }
        }
        if (existeven) return maxelem;
        else return -1;
    }
};
