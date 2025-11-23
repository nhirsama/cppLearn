//  总成绩和平均分计算

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let v: Vec<f64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    println!(
        "{:.2} {:.2}",
        v[0] + v[1] + v[2],
        (v[0] + v[1] + v[2]) / 3.0
    );
}
