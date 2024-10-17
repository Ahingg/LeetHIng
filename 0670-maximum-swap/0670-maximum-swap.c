int maximumSwap(int num) {
    if(num <= 10) return num; 
    int digit = 100000000;
    int digitCount = 8;
    int digitList[8] = {};
    
    while(digitCount > 1){
        
        if (num / digit != 0){
            break;
        }
        digitCount--;
        digit /= 10;
    }
    
    for(int i = digitCount; i >= 0; i--){
        digitList[i] = num%10;
        num /= 10;
    }
    
    int indexMax = 0;
    int j = 0;
    while(j < digitCount){
        indexMax = j;
        for(int i = j+1; i <= digitCount; i++){
            if(digitList[i] >= digitList[indexMax]) indexMax = i;
        }
        if(digitList[indexMax] != digitList[j]){
            break;
        }
        j++;
    }


    if(indexMax != j && j != digitCount){
        int temp = digitList[j];
        digitList[j] = digitList[indexMax];
        digitList[indexMax] = temp;
    }
    printf("%d %d %d", indexMax, j, digitCount);
    int final = 0;
    for(int i = 0; i <= digitCount; i++){
        final += digitList[i];
        final *= 10;
    }
    return final/10;
}