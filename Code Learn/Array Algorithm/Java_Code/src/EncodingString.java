import java.util.Scanner;
import java.util.Stack;

public class EncodingString {

    public static void main(String[] args) {
	    Scanner scan = new Scanner(System.in);
	    String a = scan.nextLine() + "@";
	    StringBuilder stringBuilder = new StringBuilder();
	    Stack<String> st = new Stack<>();
        for (int i = 0; i < a.length(); i++) {
            if(st.isEmpty() || st.peek().equalsIgnoreCase(String.valueOf(a.charAt(i)))){
                st.push(String.valueOf(a.charAt(i)));
            }
            else{
                int count = 0;
                stringBuilder.append(st.peek());
                while (!st.isEmpty()){
                    count++;
                    st.pop();
                }
                stringBuilder.append(count);
                st.push(String.valueOf(a.charAt(i)));
            }
        }
        System.out.println(stringBuilder.toString());
    }
}
