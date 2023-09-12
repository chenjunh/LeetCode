//347. Top K Frequent Elements
//===============Idea============
//Use hash map to store <nums[i],freq>
//Sort the pair according to the freq
//output first k elements
//===============Idea============
class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> hmp;
        for (int i=0;i<n;i++){
            hmp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for (auto x:hmp){
            v.push_back(make_pair(x.first,x.second));
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> output;
        for (auto x:v){
            if (k==0) return output;

            output.push_back(x.first);
            k--;
        }

        return output;
    }
};
