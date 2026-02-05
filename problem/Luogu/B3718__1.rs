//  B3718 扔骰子问题 1

use std::io::{self, Read};

struct Scanner {
    tokens: std::vec::IntoIter<String>,
}

impl Scanner {
    fn new() -> Self {
        let mut content = String::new();
        io::stdin().read_to_string(&mut content).unwrap();
        let tokens: Vec<String> = content
            .split_whitespace()
            .map(|s| s.to_owned())
            .collect();
        Self { tokens: tokens.into_iter() }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.tokens.next().unwrap().parse().ok().expect("Parse error")
    }
}
const P: i32 = 998244353;
fn qpow(mut a: i32, mut b: i32) -> i32 {
    if P == 1 { return 0; }
    let mut res = 1;
    a %= P;

    while b > 0 {
        if b % 2 == 1 {
            res = (res as i64 * a as i64 % P as i64) as i32;
        }
        a = (a as i64 * a as i64 % P as i64) as i32;
        b /= 2;
    }
    res as i32
}
fn main() {
    const N: i32 = 5000010;
    let mut pow5 = vec![0, N];
    let mut inv6 = vec![0, N];
    for i in 1..N {
        pow5[i] = pow5[i - 1] as i64 * 5 % P;
    }
    let mut cin = Scanner::new();
    let t: i32 = cin.next();
    let mut ans = 0;
    for _ in 0..t {
        let n: i32 = cin.next();


        let m: i32 = cin.next();
        ans ^= {
            qpow(qpow(6, P - 2), m) as i64 * qpow(5 * qpow(6, P - 2), n - m) as i64 % P as i64
        }
    }
    println!("tou");
    println!("{}", ans);
}
