int minAddToMakeValid(char* s) {
    int open = 0;
    int min = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '('){
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
    }
    return open ? open + min : min;
}