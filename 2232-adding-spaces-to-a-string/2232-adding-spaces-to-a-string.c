char* addSpaces(char* s, int* spaces, int spacesSize) {
    int index = 0;

    int strLen = strlen(s);
    int totalLen = spacesSize + strLen;
    char *string = (char*)malloc((totalLen+1) * sizeof(char));
    

    for(int i = 0; i < strLen; i++){
        
        if(index < spacesSize && i == spaces[index]){
            string[i + index] = ' ';
            index++;
        }
        
        string[i + index] = s[i]; 
    }
    string[totalLen] = '\0';
    return string;
}