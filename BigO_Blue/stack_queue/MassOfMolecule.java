package stack_queue;

import java.util.Scanner;
import java.util.Stack;

public class MassOfMolecule {
    public static int mass(char c) {
        return c == 'H' ? 1 : (c == 'C' ? 12 : 16);
    } 

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();
        Stack<Integer> stack = new Stack<>();
        int w = 0, mol = 0;
        for(char c: s.toCharArray()) {
            if (Character.isLetter(c)) {
                stack.push(mass(c));
            } else if (Character.isDigit(c)) {
                mol = stack.peek() * (c - '0');
                stack.pop();
                stack.push(mol);
            } else if (c == '(') {
                stack.push(-1);
            } else {
                w = 0;
                while (stack.peek() != -1) {
                    w += stack.pop();
                }
                stack.pop();
                stack.push(w);
            }
        }

        w = 0;
        while(!stack.isEmpty()) {
            w += stack.pop();
        }
        System.out.println(w);
    }
}