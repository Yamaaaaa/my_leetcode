class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        ListNode* result;
        ListNode* current;
        current = new ListNode(0);
        result = current;
        do{
            current->next = new ListNode(l1->val + l2->val + flag);
            current = current->next;
            l1 = l1->next; l2 = l2->next;
            if(current->val >= 10){
                current->val -= 10;
                flag = 1;
            } else{
                flag = 0;
            }

        }while(l1!=NULL && l2!=NULL);
        if(l1 != NULL){
            ListNode* temp = l1;
            while(flag){
                temp->val = (temp->val + flag) ==10 ? 0:temp->val+flag ;
                flag = temp->val? 0:1;
                if(temp->next == NULL&&flag){
                    temp->next = new ListNode(1);
                    break;
                }
                temp = temp->next;
            }
            current->next = l1;
        } else if(l2 != NULL) {
            ListNode* temp = l2;
            while(flag){
                temp->val = (temp->val + flag) ==10 ? 0:temp->val+flag ;
                flag = temp->val? 0:1;
                if(temp->next == NULL&&flag){
                    temp->next = new ListNode(1);
                    break;
                }
                temp = temp->next;
            }
            current->next = l2;
        } else{
            if(flag){
                current->next = new ListNode(1);
            }
        }
        return result->next;
    }
};

//Runtime: 28 ms, faster than 97.73% of C++ online submissions for Add Two Numbers.
//Memory Usage: 10.4 MB, less than 99.27% of C++ online submissions for Add Two Numbers.