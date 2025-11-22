//  B2001 入门测试题目

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split(' ');
    let a: i64 = input.next().unwrap().parse().unwrap();
    let b: i64 = input.next().unwrap().parse().unwrap();
    println!("{}", a + b)
}
