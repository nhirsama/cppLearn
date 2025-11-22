//  A - Happy Birthday! 4

use std::io::{self};

fn main() {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let x: i64 = input.next().unwrap().parse().unwrap();
    let y: i64 = input.next().unwrap().parse().unwrap();
    let z: i64 = input.next().unwrap().parse().unwrap();
    let mut a: i64 = 0;
    while a <= 10000 {
        if (x + a) == z * (y + a) {
            println!("Yes");
            return;
        }
        a += 1;
    }
    println!("No");
}
