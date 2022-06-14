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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* temp=head;
        vector<int> arr;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(),arr.end());
        //reverse first k element
        reverse(arr.begin(),arr.begin()+k);
        //reverse last k element
        reverse(arr.begin()+k,arr.end());
        temp=head;
        for(auto &x:arr)
        {
            temp->val=x;
            temp=temp->next;
        }
        return head;
    }
};