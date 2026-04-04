class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        if(rows == 1 || len == 0) return encodedText;
        
        string result = "";
        int column = len / rows;
        // last fully diagonal index will be:
        // amount of column - rows + 1, because 1 to 4, 2 to 5, and 3 to 6 so if there's only 6 column, then the last redirectable is from the index 2 (0 based) 
        // there will be case where: the last diagonal would be the last part of the sentence (the last character between index = 3, 3 + column, 3 + column*2)
        int lastDiagonal = column - rows;
        // buffer for storing trailing spaces that can still contain characters after ward.
        
        string trail = "";  
        for(int c = 0; c <= lastDiagonal; c++) {
            if(c < lastDiagonal) {
                for(int r = 0; r < rows; r++) {
                    int index = c + (r*column) + r;
                    result += encodedText[index];
                }
                continue;
            }
            for(int r = 0; r < rows; r++) {
                int index = c + (r*column) + r;
                if(encodedText[index] == ' ') trail += ' ';
                else {
                    trail += encodedText[index];
                    result += trail;
                    trail = "";
                }
            }
        }
        // for after last diagonal
        int c = lastDiagonal + 1;
        string trail2 = "";
        for(int r = 0; r < rows - 1; r++) {
            int index = c + (r*column) + r;
            if(encodedText[index] == ' ') trail2 += ' ';
            else {
                result = result + trail + trail2 + encodedText[index];
                trail = "";
                trail2 = "";
            } 
        }
        return result;
    }
};