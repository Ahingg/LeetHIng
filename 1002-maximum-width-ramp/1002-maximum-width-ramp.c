int maxWidthRamp(int* nums, int numsSize) {
    int rightMax[numsSize] = {};

    rightMax[numsSize-1] = nums[numsSize-1];

    for(int i = numsSize-2; i >= 0; i--){
        rightMax[i] = rightMax[i+1] > nums[i] ? rightMax[i+1] : nums[i];
    }

    int left = 0, right = 0, max = 0;

    while(right < numsSize){
        while(left < right && nums[left] > rightMax[right]){
            left++;
        }
        max = max > right - left? max : right - left;
        right++;
    }
    return max;
}