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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;
        ListNode* temp=head;

        int len=0; 
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }

        int mid=len/2;
         
         int cnt=1;
         temp=head;
         while(cnt<mid){
            temp=temp->next;
            cnt++;
         }
         temp->next=temp->next->next;
        return head;
    }
};