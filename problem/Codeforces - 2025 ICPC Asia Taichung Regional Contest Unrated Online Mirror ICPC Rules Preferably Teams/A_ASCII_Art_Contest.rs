//  A. ASCII Art Contest

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut v: Vec<i64> = input
        .split_whitespace()
        .filter_map(|x| x.parse().ok())
        .collect();
    v.sort();
    if v[2] - v[0] >= 10 {
        println!("check again");
    } else {
        println!("final {}", v[1]);
    }
}
