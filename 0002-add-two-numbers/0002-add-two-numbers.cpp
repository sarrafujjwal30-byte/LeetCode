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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int carry=0;
        int sum;
        while(temp1 || temp2)
            {   
                int digit1 = (temp1 != NULL) ? temp1->val : 0;
                int digit2 = (temp2 != NULL) ? temp2->val : 0;


                sum=digit1+digit2+carry;
                carry=sum/10;
                sum=sum%10;
                ListNode* y = new ListNode(sum);

                if (head == NULL) {
                    head = y;
                    tail = y;
                } else {
                    tail->next = y;
                    tail = y;
                }
                if (temp1) temp1 = temp1->next;
                 if (temp2) temp2 = temp2->next;

            }
            if(carry>0)
                tail->next=new ListNode(carry);
        return head;
    }
};