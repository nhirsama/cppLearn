//  A+B

use std::io::{self};

fn main() {
    let mut input = String::new();
    loop {
        input.clear();
        let t = io::stdin().read_line(&mut input).unwrap();
        if t == 0 {
            break;
        }
        let input = input
            .trim()
            .split_whitespace()
            .filter_map(|x| x.parse().ok())
            .collect::<Vec<i32>>();
        println!("{}", input[0] + input[1]);
    }
}
