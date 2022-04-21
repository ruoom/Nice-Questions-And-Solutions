struct Scanner<R> {
    reader: R,
    line: Vec<u8>,
    ptr: usize
}

impl<R: std::io::BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        return Self {reader, line: vec![], ptr: 0};
    }

    fn scan<T: std::str::FromStr>(&mut self) -> T {
        loop {
            while self.ptr < self.line.len() && self.line[self.ptr].is_ascii_whitespace() {
                self.ptr += 1;
            }
            if self.ptr != self.line.len() {
                let start = self.ptr;
                while self.ptr < self.line.len() && !self.line[self.ptr].is_ascii_whitespace() {
                    self.ptr += 1;
                }
                return std::str::from_utf8(&self.line[start..self.ptr]).unwrap().parse().ok().
                    expect("parse error");
            }
            self.line.clear();
            self.reader.read_until(b'\n', &mut self.line).expect("read error");
            self.ptr = 0;
        }
    }

}

fn gcd(a: i32, b: i32) -> i32 {
    return if a == 0 {
        b
    } else {
        gcd(b % a, a)
    }
}

fn solve<R: std::io::BufRead, W: std::io::Write>(scanner: &mut Scanner<R>, writer: &mut W) {
    let n = scanner.scan();
    let mut a = vec![0; n];
    let mut b = vec![0; n];
    for i in 0..n {
        a[i] = scanner.scan();
    }
    let mut gens = vec![0; n];
    let mut gen = 1;
    let mut order = Vec::new();
    let mut tmp = Vec::new();
    for i in 0..n {
        b[i] = gcd(a[i], a[(i + 1) % n]);
        if b[i] != a[i] {
            gens[i] = gen;
            order.push(i);
            if gens[(n + i - 1) % n] != gen {
                gens[(n + i - 1) % n] = gen;
                order.push((n + i - 1) % n);
            }
        }
    }
    std::mem::swap(&mut b, &mut a);
    while !order.is_empty() {
        gen += 1;
        tmp.clear();
        for &i in &order {
            b[i] = gcd(a[i], a[(i + 1) % n]);
            if b[i] != a[i] {
                if gens[i] != gen {
                    gens[i] = gen;
                    tmp.push(i);
                }
                if gens[(n + i - 1) % n] != gen {
                    gens[(n + i - 1) % n] = gen;
                    tmp.push((n + i - 1) % n);
                }
            }
        }
        std::mem::swap(&mut tmp, &mut order);
        std::mem::swap(&mut b, &mut a);
    }
    writeln!(writer, "{}", gen - 1).unwrap();
}

fn main() {
    let (stdin, stdout) = (std::io::stdin(), std::io::stdout());
    let mut writer = std::io::BufWriter::new(stdout.lock());
    let mut scanner = Scanner::new(stdin.lock());
    let tests: usize = scanner.scan();
    for _ in 0..tests {
        solve(&mut scanner, &mut writer);
    }
}
