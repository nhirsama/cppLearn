from math import gcd
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]  # 路径压缩
            x = self.parent[x]
        return x
    def merge(self, x, y):
        self.parent[self.find(x)] = self.find(y)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    uf = UnionFind(n)
    for i in range(n):
        uf.merge(i, a[i] - 1)
    cnt = [0] * n
    for i in range(n):
        cnt[uf.find(i)] += 1
    lcm = 1
    for c in cnt:
        if c>0:
            lcm = lcm * c // gcd(lcm, c)

    print(lcm)

if __name__ == '__main__':
    main()
