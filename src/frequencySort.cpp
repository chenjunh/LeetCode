//451. Sort Characters By Frequency
//=============Idea==============
//Same as TopKfrequent elements
//Use hash map to store pairs of char and its frequency
//Sort the pairs by frequency
//=============Idea==============
class Solution {
public:
    static bool cmp(pair<char,int> a,pair<char,int> b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> hmp;
        for (int i=0;i<n;i++){
            hmp[s[i]]++;
        }

        vector<pair<char,int>> v(hmp.begin(),hmp.end());

        sort(v.begin(),v.end(),cmp);
        
        string output;
        int count;
        for (auto x:v){
            count = x.second;
            while (count>0){
                output+=x.first;
                count--;
            }
        }
        return output;
    }
};
