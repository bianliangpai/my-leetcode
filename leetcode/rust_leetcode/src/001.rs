use std::collections::HashMap;

struct Solution {
}

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut nums_map : HashMap<i32, usize> = HashMap::new();
        for (index, &num) in nums.iter().enumerate() {
            nums_map.insert(num, index);
        }
        for (index, &num) in nums.iter().enumerate() {
            let minus : i32 = target - num;
            if let Some(&val) = nums_map.get(&minus) {
                if val != index {
                    return vec![index as i32, val as i32];
                }
                else {
                    continue
                }
            }
            else {
                continue
            };
        }
        vec![]
    }
}

fn main() {
    assert_eq!(Solution::two_sum(vec![3, 3], 6), vec![0, 1]);
    assert_eq!(Solution::two_sum(vec![2, 7, 11, 13], 9), vec![0, 1]);
    assert_eq!(Solution::two_sum(vec![3, 2, 4], 6), vec![1, 2]);
}
