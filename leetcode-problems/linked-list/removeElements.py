# 203. Remove Linked List Elements
# https://leetcode.com/problems/remove-linked-list-elements/

###################################################################################################
#
#   def removeElements(head, val):
#   1.  node <- head
#   2.  prev <- null
#   3.  while node is not null:
#   4.      if node.val == val:
#   5.          if node == head:
#   6.              head <- head.next
#   7.          else:
#   8.              prev.next <- node.next
#   9.      else:
#   10.         prev <- node
#   11.     node <- node.next
#   12. return head
#
#   Time complexity:    O(N) to search all nodes for the target value
#   Space complexity:   O(1) to store current and previous nodes
#
###################################################################################################
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def removeElements(head, val):
    node = head
    prev = None
    while node:
        if node.val == val:
            if not prev:
                head = head.next
            else:
                prev.next = node.next
        else:
            prev = node
        node = node.next

    return head

# Test cases
head1 = ListNode(1)
node1 = head1
j = 0
for i in range(0, 6):
    if i == 1 or i == 5:
        node1.next = ListNode(6)
    else:
        node1.next = ListNode(j + 2)
        j += 1
    node1 = node1.next
head1 = removeElements(head1, 6)
node1 = head1
while node1:
    print(str(node1.val) + " -> ", end = '')
    node1 = node1.next
print('*')

head2 = None
head2 = removeElements(head2, 1)
node2 = head2
while node2:
    print(str(node2.val) + " -> ", end = '')
    node2 = node2.next
print('*')

head3 = ListNode(7)
node3 = head3
for _ in range(0, 3):
    node3.next = ListNode(7)
    node3 = node3.next
head3 = removeElements(head3, 7)
node3 = head3
while node3:
    print(str(node3.val) + " -> ", end = '')
    node3 = node3.next
print('*')
