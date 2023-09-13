//692. Top K Frequent Words
//==================Idea=================
//This is an extension problem of the top frequent even numbers, with one more sub-sorting-criteria besides frequency -- lexicographical order
//The same as top frequent even numbers: hash map, sort vector pair
//Only different part: sort the words with the same frequency by lexicographical order
//And this is realized by: sort(wordsofsamefrequency.begin(),wordsofsamefrequency.end())
//If one wants to sort by descending order, just add one more line after sort: reverse(wordsofsamefrequency.begin(),wordsofsamefrequency.end())
//==================Idea=================
class Solution {
public:
    static bool cmp(pair<string,int> a,pair<string,int> b) {
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> hmp;
        for (int i=0;i<n;i++){
            hmp[words[i]]++;
        }
        vector<pair<string,int>> v(hmp.begin(),hmp.end());
        sort(v.begin(),v.end(),cmp);

        int prev=v[0].second;
        vector<string> samefreq;//strings with the same frequency
        vector<string> sorted_samefreq;//sort the strings with the same frequency by lexicographical order
        vector<string> results;//All strings sorted by frequency from highest to lowest and by lexicographical order for those with the same frequency
        for (auto x:v){
            if(x.second!=prev){//if current string has different frequency than the previous one, process the strings with the same frequency stored in "samefreq" vector
                sorted_samefreq=samefreq;
                sort(sorted_samefreq.begin(),sorted_samefreq.end());
                samefreq.clear();
                prev=x.second;
                for (auto y:sorted_samefreq) 
                    results.push_back(y);
            }
            samefreq.push_back(x.first);//the current string has not been added to the "results" vector, store it for now
        }

        sort(samefreq.begin(),samefreq.end());
        for (auto x:samefreq) {
            results.push_back(x);
        }

        vector<string> final;
        for (auto x:results){
            if (k==0) break;
            final.push_back(x);
            k--;
        }

        return final;

    }
};
