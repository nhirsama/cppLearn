#  B. Choosing Cubes
def nhir():
    n, m, p = map(int, input().split())
    arr = list(map(int, input().split()))
    t = arr[m - 1]
    arr.sort(reverse=True)
    flag = [0, 0]
    for i in range(n):
        if i < p and arr[i] == t:
            flag[0] = 1
        elif i >= p and arr[i] == t:
            flag[1] = 1
    if flag[0] == 1 and flag[1] == 1:
        print("MAYBE")
    elif flag[1] == 1:
        print("NO")
    else:
        print("YES")


__T = int(input())
for __ in range(__T):
    nhir()
