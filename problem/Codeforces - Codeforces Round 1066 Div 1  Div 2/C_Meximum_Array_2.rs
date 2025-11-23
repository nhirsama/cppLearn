//  C. Meximum Array 2

use std::io::{self, Read};

fn solve(it: &mut std::str::SplitWhitespace<'_>) {
    let n: i32 = it.next().unwrap().parse().unwrap();
    let k: i32 = it.next().unwrap().parse().unwrap();
    let q: i32 = it.next().unwrap().parse().unwrap();
    // let mut v: Vec<(i32, i32, i32)> = Vec::new();
    let mut min: Vec<(usize, usize)> = Vec::new();
    let mut mex: Vec<(usize, usize)> = Vec::new();
    for _ in 0..q {
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        let c: usize = it.next().unwrap().parse().unwrap();
        if a == 1 {
            min.push((b - 1, c - 1));
        } else {
            mex.push((b - 1, c - 1));
        }
    }
    let mut ans: Vec<i32> = vec![k + 1; n as usize];
    let mut minn: Vec<bool> = vec![false; n as usize];
    let mut mexx: Vec<bool> = vec![false; n as usize];
    for i in &min {
        for j in i.0..=i.1 {
            minn[j] = true;
        }
    }

    for i in &mex {
        for j in i.0..=i.1 {
            mexx[j] = true;
        }
    }
    for i in &min {
        let mut f = false;
        for j in i.0..=i.1 {
            if ans[j] == k {
                f = true;
                break;
            }
        }
        if !f {
            for j in (i.0..=i.1).rev() {
                if !mexx[j] {
                    ans[j] = k;
                    break;
                }
            }
        }
    }
    let mut cnt = 0;
    for i in &mex {
        for j in i.0..=i.1 {
            if minn[j] {
                continue;
            } else if mexx[j] {
                ans[j] = -1;
            }
        }
    }
    for i in 0..n {
        if ans[i as usize] == -1 {
            ans[i as usize] = cnt % k;
            cnt += 1;
        }
    }
    for i in &ans {
        print!("{} ", i);
    }
    println!();
}
fn main() {
    let mut input: String = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();
    let t = it.next().unwrap().parse::<i32>().unwrap();
    for _ in 0..t {
        solve(&mut it);
    }
}
