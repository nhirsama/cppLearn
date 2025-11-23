//  A. Dungeon Equilibrium

use std::io::{self};

fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    input.clear();
    let mut v: Vec<i32> = vec![0; n as usize + 1];
    io::stdin().read_line(&mut input).unwrap();
    let input: Vec<i32> = input
        .trim()
        .split_whitespace()
        .filter_map(|x| x.parse().ok())
        .collect();
    for i in input {
        v[i as usize] += 1;
    }
    let mut cnt = 0;
    for i in 0..=n as usize {
        if v[i] != 0 {
            if v[i] >= (i) as i32 {
                cnt += v[i] - (i) as i32;
            } else {
                cnt += v[i];
            }
        }
    }
    println!("{}", cnt);
}
fn main() {
    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t = t.trim().parse::<i32>().unwrap();
    for _ in 0..t {
        solve();
    }
}
