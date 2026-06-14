class Solution {
public:
    int pairSum(ListNode* head) {
           int len=0;

           ListNode* temp=head;
           while(temp!=NULL){
             len++;
            temp=temp->next;
           }  
           
           ListNode* first=head;

           temp=head;
           
           int cnt=1;
           while(cnt<(len)/2){
            cnt++;
            temp=temp->next;
           }
            
          
           ListNode* second=temp->next;
           temp->next=NULL;


           //reverse 2nd half
           ListNode* nexts=second->next;
           ListNode* curr=second;
           ListNode* prev=NULL;

           while(curr!=NULL){
               curr->next=prev;
               prev=curr;
               curr=nexts;
             if(nexts!=NULL)  nexts=nexts->next;
           }


           int ans=0;

           while(prev!=NULL){
            ans=max(ans,prev->val+first->val);
            prev=prev->next;
            first=first->next;
           }
           return ans;
            
    }
};