class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      ListNode* newhead=NULL;
      ListNode* temp=newhead;
      set<int>st;
      for(int ele:nums) st.insert(ele);

      ListNode* temp2=head;
      while(temp2!=NULL){
        if(st.find(temp2->val)!=st.end()) temp2=temp2->next;
        else{
            if(newhead==NULL){
                 newhead=temp2;
                 temp=newhead;
            } else{
                temp->next=temp2;
                temp=temp->next;
            }
           temp2=temp2->next;
        }
      }
      temp->next=NULL;

      return newhead;

    }
};