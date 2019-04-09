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
        for(j=i+1;j<numsSize;j++)
        {
            if(i==j)
                continue;
            if(nums[i]+nums[j]==target)
            {
                lalala[0]=i;
                lalala[1]=j;
                return lalala;
            }
        }
    }
}