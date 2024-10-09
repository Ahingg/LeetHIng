int minSwaps(char* s) {
    int open = 0;
    int min = 0;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == '['){
            open++;
        }
        else {
            if (open > 0) {
                open--;
            }
            else{
                min++;
            }
        }
        i++;
    }
    // printf("%d %d", open, min); 
    return ceil((open + min)/4.0);
}