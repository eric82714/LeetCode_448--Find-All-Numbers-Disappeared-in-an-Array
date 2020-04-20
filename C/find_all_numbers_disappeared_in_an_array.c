/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b){  
    int tmp = *a;  
    *a = *b;  
    *b = tmp;  
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int* result = malloc(numsSize * sizeof(int));
          
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != nums[nums[i] - 1]){
            swap(&nums[i], &nums[nums[i]-1]);
            i--;
        }
    }
    
    int index = 0;
    
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != i + 1){
            result[index] = i + 1;
            index ++;
        }
    }
    
    *returnSize = index;
    return result;

}
