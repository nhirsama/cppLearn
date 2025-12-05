//  A - Balloon Trip

use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let m: i32 = input.next().unwrap().parse().unwrap();
    let b: i32 = input.next().unwrap().parse().unwrap();
    println!("{}", (m*1000) / b + 1);
}
