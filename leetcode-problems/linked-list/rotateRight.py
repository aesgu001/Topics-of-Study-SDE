# 61. Rotate List
# https://leetcode.com/problems/rotate-list/

###################################################################################################
#
#   def rotateRight(head, k):
#   1.  size <- 1
#   2.  last <- head
#   3.  while last != null and last.next != null
#   4.      size <- size + 1
#   5.      last <- last.next
#   6.  if size <= 1:
#   7.      return head
#   8.  if k > size:
#   9.      k <- k % size
#   10. k <- size - k
#   11. if k == 0 or k == size:
#   12. return head
#   13. node <- head
#   14. prev <- null
#   15. for _ from 0 to k:
#   16.     prev <- node
#   17.     node <- node.next
#   18. last.next <- head
#   19. prev.next <- null
#   20. head <- node
#   21. return head
#
#   Time complexity:    O(N) to use the last node
#                       O(N) to move the head node to kth node
#                       O(N) + O(N) = (N)
#   Space complexity:   O(1) to store prev, curr, and last nodes
#
###################################################################################################
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def rotateRight(head, k):
    # Get list size and last node
    size = 1
    last = head
    while last and last.next:
        size += 1
        last = last.next

    # Return head if list has 0 or 1 node
    if size < 2:
        return head
    
    # Calculate head position after k rotations
    if k > size:
        k %= size
    k = size - k

    # Return head if final state == initial state
    if k == 0 or k == size:
        return head

    # Get current and previous nodes
    node = head
    prev = None
    for _ in range(0, k):
        prev = node
        node = node.next

    # Move last->next to head
    # Move prev->next to null
    # Move head to current
    last.next = head
    prev.next = None
    head = node

    return head

# Test cases
head1 = ListNode(1)
node1 = head1
for i in range(0, 4):
    node1.next = ListNode(i + 2)
    node1 = node1.next
head1 = rotateRight(head1, 2)
node1 = head1
while node1:
    print(str(node1.val) + " -> ", end = '')
    node1 = node1.next
print('*')

head2 = ListNode(0)
node2 = head2
for i in range(0, 2):
    node2.next = ListNode(i + 1)
    node2 = node2.next
head2 = rotateRight(head2, 4)
node2 = head2
while node2:
    print(str(node2.val) + " -> ", end = '')
    node2 = node2.next
print('*')
