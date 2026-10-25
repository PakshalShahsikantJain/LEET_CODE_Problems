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

PNODE reverseBetween(PNODE head,int left,int right) {
    PNODE prev = NULL;
    PNODE curr = NULL;
    PNODE before = NULL;
    // PNODE after = NULL;

    PNODE dummy = (PNODE)malloc(sizeof(NODE));

    dummy->val = 0;
    dummy->next = head;

    int i = 0;

    before = dummy;

    for(i = 1;i < left;i++)
    {
        before = before -> next;
    }

    curr = before -> next;

    while (curr != NULL && i <= right) {
        PNODE next_node = curr->next; 
        curr->next = prev;                      
        prev = curr;                            
        curr = next_node;           
        
        i++;
    }

    before->next->next = curr;
    before->next = prev;

    head = dummy->next;

    free(dummy);

    return head; 
}
