/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) 
{
    int i,j;
    int * lalala=(int *)malloc(sizeof(int)*2);
    int flag=0;
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize;j++)     //actually there is no need traversing from beginning
        {
            if(i==j)
                continue;
            if(nums[i]+nums[j]==target)
            {
                lalala[0]=i;
                lalala[1]=j;
                flag=1;             //return but not break
                break;
            }
        }
        if(flag)
            break;
    }
    return lalala;
}
//Runtime: 188 ms
//Memory Usage: 7.3 MB