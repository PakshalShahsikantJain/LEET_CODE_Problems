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
    // int arr[10001] = {0};

    int i = 0;

    // for(i = 0;i < numsSize;i++)
    // {
    //     arr[nums[i]] = 1;
    // }

    while (head != NULL)
    {
        int currInNums = 0;

        for(i = 0;i < numsSize;i++)
        {
            if(head->val == nums[i])
            {
                currInNums = 1;
                break;
            }
        }

        if (currInNums && !prevInNums)
        {
            icnt++;
        }

        prevInNums = currInNums;
        head = head->next;
    }

    return icnt;
}