//  A. Codeforces Checking

// use io::stdin;
use std::io::{self};
fn main() {
    let base = "codeforces";
    let mut t = String::new();
    io::stdin().read_line(&mut t).expect("re");
    //let t = t.trim().split_whitespace();
    // let a: i64 = t.next().and_then(|s| s.parse().ok()).expect("re");
    let a: usize = t.trim().parse().expect("not an integer");
    for _ in 0..a {
        let mut inputc = String::new();
        io::stdin().read_line(&mut inputc).expect("re");
        let inputc = inputc.trim();
        if base.contains(inputc) {
            println!("YES");
        } else {
            println!("NO");
        }
    }
    //input.find()
}
