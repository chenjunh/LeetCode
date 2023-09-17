//5. Longest Palindromic Substring
//================Idea===================
//expand n times for odd length and for even length
//and select the longest palindromic string
//Time Complexity: O(n^2)
//Space Complexity: O(1)
//================Idea===================
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<int> ans(2,0);//store the starting and ending index for palindromic string
        int length;
        for (int i=0;i<n;i++){
            length=expand(i,i,s);//expand from the same point, odd length
            if (length>ans[1]-ans[0]+1) {
                ans[0]=i-length/2;
                ans[1]=i+length/2;
            }
            length=expand(i,i+1,s);//expand from two nearest points, even length
            if (length>ans[1]-ans[0]+1){
                ans[0]=i-length/2+1;
                ans[1]=i+length/2;
            }
        }
        return s.substr(ans[0],ans[1]-ans[0]+1);
    }
    int expand(int i,int j, string &s){//expand from [i,j] to [i-1,j+1],[i-2,j+2],... (i<=j)
        int left=i;
        int right=j;
        int n=s.size();
        while (left>=0 && right<n){
            if (s[left]!=s[right]) return right-left-1;
            left--;
            right++;
        }
        return right-left-1;//return length of the valid substring
    }
};
