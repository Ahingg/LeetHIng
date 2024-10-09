class Solution {
    
    Stack<Character> stack = new Stack<>(); 

    public int minAddToMakeValid(String s) {
        if(s.isEmpty()) return 0;
        for(int i = 0; i < s.length(); i++){
            
            if(!stack.empty()){
                if(stack.peek() == '(' && s.charAt(i) == ')'){
                    stack.pop();
                    continue;
                }
            }
            
            stack.push(s.charAt(i));
            
        }
        return stack.size();
    }
}