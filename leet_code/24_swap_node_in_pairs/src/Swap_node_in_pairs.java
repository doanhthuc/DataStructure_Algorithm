import java.util.List;

public class Swap_node_in_pairs {
     public static class ListNode {
         int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     }

    static class Solution {
        public ListNode swapPairs(ListNode head) {
            if(head == null) return null;
            if(head.next == null) return head;

            ListNode nextNode = head.next;
//            Swap head and nextNode
            head.next = nextNode.next;
            nextNode.next = head;

            // Xu li bai toan con
            ListNode newHead = swapPairs(head.next);
            // noi bai toan hien tai vao bai toan con
            head.next = newHead;

            return nextNode;
        }
    }

    public static void printSolution(ListNode head){
         while (head != null) {
             System.out.print(head.val + "   ");
             head = head.next;
         }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(3);
        ListNode n4 = new ListNode(4);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;

        printSolution(n1);
        Solution solution = new Solution();
        ListNode newList = solution.swapPairs(n1);
        printSolution(newList);
    }

}
