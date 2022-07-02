# 432. All O'one Data Structure
# https://leetcode.com/problems/all-oone-data-structure/

###################################################################################################
#
#   Class DLNode (Doubly-linked node):
#       count:  int
#       keys:   set(string)
#       prev:   DLNode
#       next:   DLNode
#
#   Class AllOne (object):
#       begin:  DLNode (dummy)
#       end:    DLNode (dummy)
#       map:    dict{str : DLNode}
#
#       inc(key):
#       1.  if key in map:
#       2.      node <- map[key]
#       3.  else:
#       4.      node <- begin
#       5.  if node.count + 1 != node.next.count:
#       6.      next <- DLNode(count + 1)
#       7.      insert next after node
#       8.  else:
#       9.      next <- node.next
#       10. add key to next
#       11. map key to next
#       12. if node != begin and node.keys.empty:
#       13.     delete node
#       
#       Time complexity:    O(1) to map a new node and add a key
#       Space complexity:   O(1) to store node and key
#
#       dec(key):
#       1.  node <- map.pop(key)
#       2.  if node.count - 1 != node.prev.count:
#       3.      prev <- DLNode(count - 1)
#       4.      insert prev before node
#       5.  else:
#       6.      prev <- node.prev
#       7.  add key to prev
#       8.  map key to prev
#       9.  if node != begin and node.keys.empty:
#       10.     delete node
#       
#       Time complexity:    O(1) to map a new node and add a key
#       Space complexity:   O(1) to store node and key
#
#       def getMaxKey():
#       1.  if list is empty:
#       2.      return ""
#       3.  return end.prev.key
#
#       Time complexity:    O(1) to return max key value
#       Space complexity:   O(1) no extra storage necessary
#
#       def getMinKey():
#       1.  if list is empty:
#       2.      return ""
#       3.  return begin.next.key
#
#       Time complexity:    O(1) to return min key value
#       Space complexity:   O(1) no extra storage necessary
#
###################################################################################################
class DLNode(object):
    def __init__(self, count=0):
        self.count = count
        self.keys = set()
        self.prev = None
        self.next = None

    def remove(self):
        # Detach self from next and prev nodes
        self.prev.next = self.next
        self.next.prev = self.prev
        self.next = self.prev = None

    def insert(self, node, before=False):
        # Attach node before self
        if before:
            self.prev.next = node
            node.prev = self.prev
            node.next = self
            self.prev = node
        # After
        else:
            self.next.prev = node
            node.prev = self
            node.next = self.next
            self.next = node

class AllOne(object):
    def __init__(self):
        # Init doubly-linked list with dummy head and tail nodes
        self.begin = DLNode()
        self.end = DLNode()
        self.begin.next = self.end
        self.end.prev = self.begin
        # Init key map
        self.map = {}

    def inc(self, key):
        # Get node mapped by key and remove key from node
        node = self.begin
        if key in self.map:
            node = self.map[key]
            node.keys.remove(key)

        # Insert new node after if count + 1 != next.count
        next = node.next
        if node.count + 1 != next.count:
            next = DLNode(node.count + 1)
            node.insert(next)
        
        # Map key to 'next'
        next.keys.add(key)
        self.map[key] = next

        # Remove non-dummy node if there are no keys left
        if node.count != 0 and not node.keys:
            node.remove()

    def dec(self, key):
        if key not in self.map:
            return
        
        # Get node mapped by key and remove key from node
        node = self.map.pop(key)
        node.keys.remove(key)

        # Insert new node before if count - 1 != prev.count
        prev = node.prev
        if node.count - 1 != prev.count:
            prev = DLNode(node.count - 1)
            node.insert(prev, True)

        # Map key to 'prev' if node.count - 1 > 0
        if prev.count != 0:
            prev.keys.add(key)
            self.map[key] = prev

        # Remove non-dummy node if there are no keys left
        if node.count != 0 and not node.keys:
            node.remove()

    def getMaxKey(self):
        # Return max key value or "" if list is empty
        if self.end.prev.count == 0:
            return ""
        key = self.end.prev.keys.pop()
        self.end.prev.keys.add(key)
        return key

    def getMinKey(self):
        # Return min key value or "" if list is empty
        if self.begin.next.count == 0:
            return ""
        key = self.begin.next.keys.pop()
        self.begin.next.keys.add(key)
        return key

# Test cases
allOne1 = AllOne()
allOne1.inc("hello")
allOne1.inc("hello")
print(allOne1.getMaxKey())   # "hello"
print(allOne1.getMinKey())   # "hello"
allOne1.inc("leet")
print(allOne1.getMaxKey())   # "hello"
print(allOne1.getMinKey())   # "leet"

allOne2 = AllOne()
allOne2.inc("a")
allOne2.inc("b")
allOne2.inc("b")
allOne2.inc("c")
allOne2.inc("c")
allOne2.inc("c")
allOne2.dec("b")
allOne2.dec("b")
print(allOne2.getMinKey())  # "a"
allOne2.dec("a")
print(allOne2.getMaxKey())  # "c"
print(allOne2.getMinKey())  # "c"
