/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode NODE;
typedef struct ListNode * PNODE;
typedef struct ListNode ** PPNODE;

bool hasCycle(PNODE Head) {
    bool bret = FALSE;

    PNODE slow = Head;
    PNODE fast = Head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            bret = TRUE;
            break;
        }
    }

    return bret;     
}