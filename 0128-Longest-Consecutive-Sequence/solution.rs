use std::collections::HashSet;

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let set: HashSet<i32> = nums.into_iter().collect();
        let mut max_streak = 0;

        for &val in &set {
            // Only start counting if val is the start of a streak
            if !set.contains(&(val - 1)) {
                let mut current_val = val;
                let mut current_streak = 1;

                while set.contains(&(current_val + 1)) {
                    current_val += 1;
                    current_streak += 1;
                }

                max_streak = max_streak.max(current_streak);
            }
        }

        max_streak
    }
}
