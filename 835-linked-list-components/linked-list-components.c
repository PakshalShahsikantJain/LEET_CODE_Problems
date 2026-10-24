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

int numComponents(PNODE head, int* nums, int numsSize) {
    int icnt = 0;
    int prevInNums = 0;
    int arr[10001] = {0};

    int i = 0;

    for(i = 0;i < numsSize;i++)
    {
        arr[nums[i]] = 1;
    }

    while (head != NULL)
    {
        int ok = 0 ;

        while(head != NULL && arr[head->val])
        {
            ok = 1;
            // arr[head->val] = 0;
            head = head->next;
        }

        if(ok) 
        {
            icnt++;
        }

        if(head) 
        {
            head = head->next;
        }
    }

    return icnt;
}