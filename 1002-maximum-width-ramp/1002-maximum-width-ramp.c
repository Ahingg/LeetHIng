int maxWidthRamp(int* nums,const int numsSize) {
    int monoStack[numsSize] = {};
    int stackTop = -1;

    monoStack[0] = 0;
    stackTop = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] < nums[monoStack[stackTop]]){
            monoStack[stackTop+1] = i;
            stackTop++;
        }
    }

    int max = 0;
    for(int i = numsSize-1; i >= 0; i--){
        if(stackTop == -1){
            break;
        }

        while(stackTop >= 0 && nums[i] >= nums[monoStack[stackTop]]){
            const int len = i - monoStack[stackTop];
            if(len > max) max = len;
            stackTop--;
        }
    }

    return max;
}