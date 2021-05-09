// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}

impl Solution {
  pub fn add_two_numbers_backup(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let i1: i64 = Solution::get_number(l1);
    let i2: i64 = Solution::get_number(l2);
    let i3 = i1 + i2;
    let l3 = Solution::get_nodelist(i3);
    l3
  }

  pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut result: Option<Box<ListNode>> = None;
    let mut h1: Option<Box<ListNode>> = l1;
    let mut h2: Option<Box<ListNode>> = l2;
    let mut tail: Option<&mut Box<ListNode>> = None;
    let mut addon: i32 = 0;
    loop {
      let mut is_end1: bool = false;
      let mut is_end2: bool = false;
      let i1: i32;
      let i2: i32;
      if let Some(node) = h1 {
        i1 = node.val;
        h1 = node.next;
      }
      else {
        i1 = 0;
        is_end1 = true;
      }
      if let Some(node) = h2 {
        i2 = node.val;
        h2 = node.next;
      }
      else {
        i2 = 0;
        is_end2 = true;
      }

      if is_end1 && is_end2 {
        if addon > 0 {
          if let Some(node) = tail {
            node.next = Some(Box::new(ListNode::new(addon)));
          }
        }
        return result;
      }
      else {
        let cur_result: i32 = i1 + i2 + addon;
        addon = cur_result / 10;
        if let Some(node) = tail {
          node.next = Some(Box::new(ListNode::new(cur_result%10)));
          tail = node.next.as_mut();
        }
        else {
          result = Some(Box::new(ListNode::new(cur_result%10)));
          tail = result.as_mut();
        }
      }
    }
  }

  fn get_number(l: Option<Box<ListNode>>) -> i64 {
    let mut result: i64 = 0;
    let mut op = l;
    let mut cnt = 0;
    while let Some(node) = op {
      let i: i64 = node.val as i64;
      result = result + i64::pow(10, cnt)*i;
      cnt += 1;

      op = node.next;
    }
    result
  }

  fn get_nodelist(i: i64) -> Option<Box<ListNode>> {
    let mut num = i;
    let mut l: Option<Box<ListNode>> = None;
    let mut tail: Option<&mut Box<ListNode>> = None;
    if i == 0 {
      return Some(Box::new(ListNode::new(0)));
    }
    loop {
      if num > 0 {
        let val = (num % 10) as i32;
        num /= 10;

        if let Some(t) = tail {
          t.next = Some(Box::new(ListNode::new(val)));
          tail = t.next.as_mut();
        }
        else {
          l = Some(Box::new(ListNode::new(val)));
          tail = l.as_mut();
        }
      }
      else {
        return l;
      }
    }
  }
}

struct Solution {
}

fn main() {
  let m = Solution::get_nodelist(321);
  let n = Solution::get_nodelist(654);
  let a = Solution::get_nodelist(975);
  let s = Solution::add_two_numbers(m, n);
  assert_eq!(a, s);

  let m = Solution::get_nodelist(900);
  let n = Solution::get_nodelist(0);
  let a = Solution::get_nodelist(900);
  let s = Solution::add_two_numbers(m, n);
  assert_eq!(a, s);

  let m = Solution::get_nodelist(0);
  let n = Solution::get_nodelist(0);
  let a = Solution::get_nodelist(0);
  let s = Solution::add_two_numbers(m, n);
  assert_eq!(a, s);

  let m = Solution::get_nodelist(9);
  let n = Solution::get_nodelist(9999999991);
  let a = Solution::get_nodelist(10000000000);
  let s = Solution::add_two_numbers(m, n);
  assert_eq!(a, s);
}
