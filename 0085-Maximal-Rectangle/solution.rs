impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() || matrix[0].is_empty() {
            return 0;
        }

        let cols = matrix[0].len();
        let mut heights = vec![0; cols];
        let mut max_area = 0;

        for row in matrix.iter() {
            for (c, &val) in row.iter().enumerate() {
                if val == '1' {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            max_area = max_area.max(Self::largest_rectangle_area(&heights));
        }

        max_area
    }

    fn largest_rectangle_area(heights: &[i32]) -> i32 {
        let n = heights.len();
        let mut stack: Vec<usize> = Vec::new();
        let mut max_area = 0;

        for i in 0..=n {
            let curr_height = if i == n { 0 } else { heights[i] };

            while let Some(&top_idx) = stack.last() {
                if curr_height < heights[top_idx] {
                    stack.pop();
                    let h = heights[top_idx];
                    let w = if stack.is_empty() {
                        i as i32
                    } else {
                        (i - stack.last().unwrap() - 1) as i32
                    };
                    max_area = max_area.max(h * w);
                } else {
                    break;
                }
            }
            stack.push(i);
        }

        max_area
    }
}
