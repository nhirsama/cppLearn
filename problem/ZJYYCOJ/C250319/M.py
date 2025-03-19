##还得是python，暴力过数论题
k = int(input())
arr = [7 % k]
[arr.append((arr[-1] * 10 + 7) % k) for i in range(10**6)]
ans = -1

for i, a in enumerate(arr):
    if a == 0:
        ans = i + 1
        break

print(ans)