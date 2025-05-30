//  P1001 A+B Problem

use std::io;

fn main() {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .expect("Failed to read line");

    let mut iter = line.trim().split_whitespace();

    let a: i32 = iter
        .next()
        .and_then(|s| s.parse().ok())
        .expect("Parse error for a");
    let b: i32 = iter
        .next()
        .and_then(|s| s.parse().ok())
        .expect("Parse error for b");

    println!("{}", a + b);
}
