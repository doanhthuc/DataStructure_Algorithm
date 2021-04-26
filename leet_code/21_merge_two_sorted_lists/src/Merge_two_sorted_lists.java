public class Merge_two_sorted_lists {
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;

        if (l1.val <= l2.val){
            ListNode nextL1 = l1.next;
            ListNode nextElement = mergeTwoLists(nextL1, l2);
            l1.next = nextElement;
            return l1;
        } else {
            mergeTwoLists(l2, l1);
            return l2;
        }
    }

    public void print(ListNode head) {
        while (head != null) {
            System.out.print(head + "  ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(3);
        ListNode n3 = new ListNode(5);
        n1.next = n2; n2.next = n3;

        ListNode l1 = new ListNode(2);
        ListNode l2 = new ListNode(4);
        ListNode l3 = new ListNode(6);
        l1.next = l2; l2.next = l3;

        Merge_two_sorted_lists s = new Merge_two_sorted_lists();
        s.print(n1);
        s.print(l2);

//        ListNode newList = mergeTwoLists(n1, l1);
//        print(newList);
    }
}
