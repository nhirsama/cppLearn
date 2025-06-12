#  E. Final Countdown

def nhir():
    ans = []
    n = int(input())
    pre = [0] * n
    s = input()
    pre[0] = int(s[0])
    for i in range(1, n):
        pre[i] = int(s[i]) + pre[i - 1]
    base = 0
    for i in range(n - 1, -1, -1):
        base += pre[i]
        ans.append(str(base % 10))
        # ans += str(base % 10)
        base //= 10
    ans += str(base)
    while (len(ans) > 0 and ans[-1] == '0'):
        ans.pop()
    # ans = ans.rstrip('0')
    print("".join(ans[::-1]))


__T = int(input())
for __ in range(__T):
    nhir()
