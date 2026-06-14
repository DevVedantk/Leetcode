class Solution {
public:
    int pairSum(ListNode* head) {
           vector<int>arr;

           ListNode* temp=head;
           while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
           }  

           int ans=INT_MIN;
           int n=arr.size();
           for(int i=0;i<n;i++){
            ans=max(ans,arr[i]+arr[n-1-i]);
           }      
           return ans;
    }
};