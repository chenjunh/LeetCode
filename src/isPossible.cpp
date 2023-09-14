//659. Split Array into Consecutive Subsequences
//=============Idea=====================
//Greedy algorithm
//Each number can either be appended to an existing subsequence or used to start a new subsequence
//=============Idea=====================

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,freq_append;//"freq[i]" stores the frequency of each element occuring in "nums[i]"; "freq_append[i]" stores the number of subsequences that nums[i] can be appended to 
        for (auto i:nums){
          freq[i]++;
        }
        for (auto i:nums){
          if (freq[i]<=0) continue;
          //Since nums[i] exists, we consider two possible ways of dealing with nums[i]
          if (freq_append[i]>0){//First, we can append nums[i] to the existing subsequence
            freq[i]--;
            freq_append[i]--;
            freq_append[i+1]++;//The tail of the existing subsequence increases by 1
          }
          else if (freq[i+1]>0 && freq[i+2]>0){//Second, there is no existing subsequence to be appended to, so we create a new subsequence
            freq[i]--;
            freq[i+1]--;
            freq[i+2]--;
            freq_append[i+3]++;//the tail of the new subsequence should be i+3 (length of the subsequence should be no smaller than 3)
          }
          else return false;
        }
        return true;
    }
};
