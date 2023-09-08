#2780. Minimum Index of a Valid Split
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int> hmp;#hashmap <x,freq>
        int x=nums[0];#most frequent element, x
        int freq=0;#frequency of x in the vector
        for (int i=0;i<n;i++){#loop to find x and freq
            if (hmp.contains(nums[i])) {
                hmp[nums[i]]++;
                if (freq<hmp[nums[i]]){
                    x=nums[i];
                    freq=hmp[x];
                }
            }
            else hmp.insert({nums[i],1});
        }

        int f1=0;
        for (int i=0;i<n-1;i++){#loop to find minimum valid split index
            if (nums[i]==x) f1++;
            if (2*f1>i+1 && 2*(freq-f1)>n-i-1) return i;
        }

        return -1; 
        
    }
};
