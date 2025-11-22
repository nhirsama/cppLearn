//  B2003 输出第二个整数

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    input.next().unwrap();
    let a: i64 = input.next().unwrap().parse().unwrap();
    println!("{}", a);
}
