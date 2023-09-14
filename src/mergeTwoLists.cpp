//Merge Two Sorted Lists
//=======================Idea====================
//Compare list1->val and list2->val, link the output list to list with the smaller val
//Then move this list to the next and compare again
//Time Complexity: O(list1+list2)
//Space complexity: O(1)
//=======================Idea====================
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list=new ListNode(0);
        ListNode* output=list;//we need to return the head of the list
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val > list2->val) {
                list->next=list2;//link "list" to list2 because list2 has smaller value;
                list2=list2->next;//Move list2 to the next node
            }
            else{
                list->next=list1;
                list1=list1->next;
            }
            list=list->next;//Move list the the next node
        }
      //Link to the rest of the list
        if (list1!=nullptr){//if list1 still has some elements left
            list->next=list1;
        }
        else list->next=list2;//if list2 still has some elements left

        return output->next;
    }
};
