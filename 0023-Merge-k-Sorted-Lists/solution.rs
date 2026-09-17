use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct NodeWrapper(Box<ListNode>);

impl Ord for NodeWrapper {
    fn cmp(&self, other: &Self) -> Ordering {
        other.0.val.cmp(&self.0.val)
    }
}

impl PartialOrd for NodeWrapper {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut heap = BinaryHeap::new();

        for list in lists {
            if let Some(node) = list {
                heap.push(NodeWrapper(node));
            }
        }

        let mut dummy = Box::new(ListNode::new(0));
        let mut curr = &mut dummy;

        while let Some(NodeWrapper(mut node)) = heap.pop() {
            if let Some(next) = node.next.take() {
                heap.push(NodeWrapper(next));
            }
            curr.next = Some(node);
            curr = curr.next.as_mut().unwrap();
        }

        dummy.next
    }
}
