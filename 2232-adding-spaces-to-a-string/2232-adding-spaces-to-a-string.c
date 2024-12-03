char* addSpaces(char* s, int* spaces, int spacesSize) {
    int index = 0;
    int strIndex = 0;
    int strLen = strlen(s);
    int totalLen = spacesSize + strLen;
    char *string = (char*)malloc((totalLen+1) * sizeof(char));
    

    for(int i = 0; i < totalLen; i++){
        
        if(index < spacesSize && strIndex == spaces[index]){
            
            string[i++] = ' ';
            index++;
            
        }
        
        string[i] = s[strIndex++]; 
    }
    string[totalLen] = '\0';
    return string;
}