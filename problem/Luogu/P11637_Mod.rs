//  P11637 Mod

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
fn main() {
    let mut cin = Scanner::new();
    let a: i64 = cin.next();
    let b: i64 = cin.next();
    let p: i64 = cin.next();
    if p - a >= b {
        println!("{} {}", a, b);
    } else {
        println!("{} {}", 0, (b - (p - a)) % p);
    }
}
