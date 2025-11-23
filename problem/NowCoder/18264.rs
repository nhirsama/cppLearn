//  斐波那契

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    // let n = input.trim().parse::<i32>().unwrap();
    if let Some(last) = input.trim().chars().last() {
        if matches!(last, '0' | '2' | '4' | '6' | '8') {
            println!("{}", 1);
        } else {
            println!("{}", -1);
        }
    }
    // let mut dp: Vec<i64>;
    // dp = vec![0; 100];
    // dp[0] = 1;
    // dp[1] = 1;
    // for i in 1..99 {
    //     dp[i + 1] = dp[i] + dp[i - 1];
    //     if i >= 2 {
    //         println!("{}", dp[i - 2] * dp[i] - dp[i - 1] * dp[i - 1]);
    //     }
    // }
}
