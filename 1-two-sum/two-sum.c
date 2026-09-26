#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define EMPTY INT_MIN

typedef struct {
    int key;
    int idx;
} Entry; 

int hash(int key,int size)
{
    unsigned int h = (unsigned int)key;

    return h % size;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * arr = NULL;
    int i = 0;
    int j = 0;
    int diff = 0;
    int iCnt = 0;

    arr = (int *)malloc(2 * sizeof(int));

    int size = numsSize * 2;
    Entry * table = (Entry *)malloc(size * sizeof(Entry));
    
    for(i = 0;i < size;i++)
    {
        table[i].key = EMPTY;
        table[i].idx = 0;
    }

    for(i = 0;i < numsSize;i++)
    {
        diff = target - nums[i];
        int h = hash(diff,size);

        while(table[h].key != EMPTY)
        {
            if(table[h].key == diff)
            {
                arr[0] = table[h].idx;
                arr[1] = i;

                *returnSize = 2;
                return arr;
            }

            h = (h + 1) % size;
        }

        h = hash(nums[i],size);

        while(table[h].key != EMPTY)
        {
            h = (h + 1) % size;            
        }

        table[h].key = nums[i];
        table[h].idx = i;
    }

    free(table);
    free(arr);
    *returnSize=0;
    return NULL;

}
