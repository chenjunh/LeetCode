//215. Kth Largest Element in an Array
//===============Idea=================
//Learn to use heap: <T,vector<T>,compare<T>>
//compare=less gives largest on top (max-heap);
//compare=greater gives smallest on top (min-heap);
//We want to construct a k-size min-heap and update the min-heap when looping for the rest n-k elements
//===============Idea=================
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n=nums.size();
        for (int i=0;i<k;i++)
          pq.push(nums[i]);
        
        for (int i=k;i<n;i++){
          if (pq.top()<nums[i]) {
            pq.pop();
            pq.push(nums[i]);
          }
        }
        return pq.top();
    }
};
