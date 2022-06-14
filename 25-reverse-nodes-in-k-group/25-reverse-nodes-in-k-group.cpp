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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        while(head)
        {
            ListNode* Next=head->next;
            head->next=prev;
            prev=head;
            head=Next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* start=head,*tail=head,*ans=NULL,*prev;
        int cnt=0;
        bool flag=false;
        while(tail)
        {
            cnt++;
            if(cnt==k)
            {
                ListNode* Next=tail->next;
                tail->next=NULL;
               ListNode* newHead=reverse(start);
               if(flag==false)
               {
                   flag=true;
                   ans=newHead;
               }
                else
                {
                    prev->next=newHead;
                }
                tail=Next;
                prev=start;
                start=Next;
                cnt=0;
            }
            else if(tail->next==NULL)
            {
                prev->next=start;
                break;
            }
            else
                tail=tail->next;
        }
        return ans;
    }
};