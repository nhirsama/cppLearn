//  B. Expansion Plan 2

use std::io::{self};

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut input = input.trim().split_whitespace();
    let _n = input.next().unwrap().parse::<i64>().unwrap();
    let x = input.next().unwrap().parse::<i64>().unwrap();
    let y = input.next().unwrap().parse::<i64>().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut f: i64 = 0;
    let mut ni: i64 = 0;
    for i in input.trim().chars() {
        if i == '4' {
            f += 1;
            // println!("{}", i);
        } else {
            ni += 1;
        }
    }
    let x = if x.abs() <= ni { 0 } else { x.abs() - ni };
    let y = if y.abs() <= ni { 0 } else { y.abs() - ni };
    if x + y <= f {
        println!("YES");
    } else {
        println!("NO");
    }
}
fn main() {
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t = t.trim().parse::<i32>().unwrap();
    for _ in 0..t {
        solve();
    }
}
