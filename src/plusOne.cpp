//66. Plus One
//Time Complexity: O(n)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> output=digits;
        for (int i=n-1;i>-1;i--){
            if (digits[i]+1<10) {//If the current digit doesn't carry the higher digit
                output[i]=digits[i]+1;
                return output;
            }
            if (i==0) {//If the carrying digit is the first digit, e.g. 9, 99, 999
                output[i]=1;//set the first digit to be one
                output.push_back(0);//add one more 0 at the end
            }
            else output[i]=0;
        }
        
        return output;
    }
};
