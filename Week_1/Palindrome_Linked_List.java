// problem description: https://surl.gd/jfaxyc
// solution below

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> lst = new ArrayList<Integer>();
        while(head != null) {
            lst.add(head.val);
            head = head.next;
        }
        // add the value of each node in the linked list into an arraylist
        // compare pair to pair elements of that arraylist  
        int low = 0;
        int high = lst.size() - 1; 
        while(low <= high) {
            if(lst.get(low) != lst.get(high)) return false;
            low++;
            high--;
        }
        return true;
    }
}
