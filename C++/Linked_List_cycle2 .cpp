//https://leetcode.com/problems/linked-list-cycle-ii/
//Using map
//LINEAR SPACE

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        unordered_map<ListNode*,int> m;
        while(slow!=NULL){
            m[slow]++;
            if(m[slow]==2)
                return slow;
            slow=slow->next;
        }
        return NULL;  
    }
};