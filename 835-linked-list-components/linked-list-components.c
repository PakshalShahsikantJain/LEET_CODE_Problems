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
    int arr[10001] = {0};
    int i;

    for (i = 0; i < numsSize; i++)
    {
        arr[nums[i]] = 1;
    }

    while (head != NULL)
    {
        if (arr[head->val])
        {
            icnt++;                       // a run starts here
            while (head != NULL && arr[head->val])
            {
                head = head->next;        // skip the whole run
            }
        }
        else
        {
            head = head->next;            // skip a non-member
        }
    }

    return icnt;
}