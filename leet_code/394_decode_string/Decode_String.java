import java.util.Stack;

public class Decode_String {
    public static String decodeString(String s) {
        int n = s.length();
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == ']') {
                String loopStr = "";
                while(stack.peek() != '[') {
                    loopStr = stack.pop() + loopStr;
                }

                stack.pop();

                //Get number
                String numberString = "";
                while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                    numberString = stack.pop() + numberString;
                }
                int nLoop = Integer.parseInt(numberString);
                
                // Repeat the string
                loopStr = loopStr.repeat(nLoop);
                
                // Add the result back to the stack
                for (int j = 0; j < loopStr.length(); j++) {
                    stack.push(loopStr.charAt(j));
                }
            } else {
                stack.push(c);
            }
        }
        String result = "";
        while(!stack.isEmpty()) {
            result = stack.pop() + result;
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(decodeString("2[ab2[c]]"));
    }
}