//229. Majority Element II
//==============Idea=============


//==============Idea=============
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=1,count2=0;
        int me1=nums[0],me2=-pow(10,9);
        int n=nums.size();
        for (int i=1;i<n;i++){
            if (count1==0 && nums[i]!=me2){
                me1=nums[i];
                count1=1;
            }
            else if (count2==0 && nums[i]!=me1){
                me2=nums[i];
                count2=1;
            }
            else if (nums[i]==me1) count1++;
            else if (nums[i]==me2) count2++;
            else {
                count1--;
                count2--;
            }
        }
        int freq1=0,freq2=0;
        for (int i=0;i<n;i++){
            if (count1>0 && nums[i]==me1) freq1++;
            if (count2>0 && nums[i]==me2) freq2++;
        }
        
        vector<int> vme;
        if (freq1*3>n) vme.push_back(me1);
        if (freq2*3>n) vme.push_back(me2);
        return vme;
    }
};
