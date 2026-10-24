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

void InsertFirst(PPNODE Head,int data) 
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->val = data;
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

void deleteLast(PPNODE Head) 
{
    PNODE freeNode = NULL;
    PNODE temp = *Head;

    while(temp->next->next != NULL)
    {
        
        temp = temp->next;
    }

    freeNode = temp->next;
    temp->next = NULL;

    InsertFirst(&(*Head),freeNode->val);
    free(freeNode);
}

int Count(PNODE Head)
{
    int icnt = 0;

    while(Head != NULL)
    {
        icnt++;
        Head = Head->next;
    }

    return icnt;
}

struct ListNode* rotateRight(PNODE head, int k) {
    PNODE temp = head;
    int i = 0;

    int icnt = 0;

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    icnt = Count(head);

    for(i = 1;i <= k % icnt;i++)
    {
        deleteLast(&temp);
    }

    return temp;
}