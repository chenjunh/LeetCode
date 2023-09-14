//14. Longest Common Prefix
//===================Idea=================
//Sort the string vectors and compare the first and the last string
//Time Complexity: O(NlogN)
//Space Complexity: O(1)
//===================Idea=================

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        string output="";
        for (int i=0;i<min(first.size(),last.size());i++){
            if (first[i]!=last[i]) return output;
            output += first[i];
        }
        return output;
    }
};
