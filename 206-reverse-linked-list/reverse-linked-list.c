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

void InsertFirst(PPNODE Head,int no) 
{   
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->val = no;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else 
    {
        newn->next = *Head;
        *Head = newn;
    }
}

PNODE reverseList(PNODE Head)
{
    PNODE temp = NULL;

    while(Head != NULL)
    {
        InsertFirst(&temp,Head->val);
        Head = Head->next;
    }

    return temp;
}

// struct ListNode* reverseList(struct ListNode* head) {
    
// }