from collections import deque
def get_prefix(a, b):
    pre = deque([0])
    j = count = 0
    for i in range(n):
        if a[i] >= b[j]:
            count += 1
            j += 1
        pre.append(count)
        if j == m:
            break
    return pre

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    pre = get_prefix(a, b)
    suf = get_prefix(a[::-1], b[::-1])
    suf.reverse()
    while len(pre) < n + 1:
        pre.appendleft(0)
    while len(suf) < n + 1:
        suf.append(0)
    ans = float('inf')
    for i in range(n+1):
        count = pre[i] + suf[i]
        if count >= m:
            ans = 0
        elif count == m - 1:
            ans = min(ans, b[pre[i]])
    print(ans if ans < float('inf') else -1)