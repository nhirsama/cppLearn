//  B - Nearest Taller
use std::io::{self};

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input
        .trim()
        .split_whitespace()
        .next()
        .unwrap()
        .parse()
        .unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let v: Vec<i64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    println!("");
    for i in 0..n {
        let mut f = false;
        for j in (0..i).rev() {
            if v[j] > v[i] {
                println!("{}", j + 1);
                f = true;
                break;
            }
        }
        if !f {
            println!("{}", -1);
        }
    }
}
