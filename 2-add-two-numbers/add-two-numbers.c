// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

typedef struct ListNode LISTNODE; 
typedef struct ListNode * PNODE; 
typedef struct ListNode ** PPNODE; 

void InsertLast(PPNODE Head,int No)
{
    PNODE newn = (PNODE)malloc(sizeof(LISTNODE));
    PNODE temp = *Head;

    newn->val = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else    
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    PNODE result = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL) 
        { 
            sum = sum + l1->val; 
            l1 = l1->next; 
        }
        
        if (l2 != NULL) 
        { 
            sum = sum + l2->val; 
            l2 = l2->next; 
        }

        carry = sum / 10;
        InsertLast(&result, sum % 10);
    }

    return result;
}