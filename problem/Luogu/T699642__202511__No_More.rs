//  T699642 [语言月赛 202511] 曼波 No More

use std::io::{self};

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let v: Vec<i64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let mut b: Vec<i64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    b[2] += 1;
    b[3] += 1;
    println!(
        "{}",
        (((b[2] - b[0]) + v[2] - 1) / v[2]) * (((b[3] - b[1]) + v[3] - 1) / v[3])
    );
}
