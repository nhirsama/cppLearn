//  B. Lasers

use std::io::{self};

fn nhir() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let v: Vec<i64> = input
        .split_whitespace()
        .filter_map(|x| x.parse().ok())
        .collect();
    io::stdin().read_line(&mut input).unwrap();
    io::stdin().read_line(&mut input).unwrap();
    println!("{}", v[0] + v[1]);
}
fn main() {
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t: i32 = t.trim().parse().unwrap();
    for _ in 0..t {
        nhir();
    }
}
