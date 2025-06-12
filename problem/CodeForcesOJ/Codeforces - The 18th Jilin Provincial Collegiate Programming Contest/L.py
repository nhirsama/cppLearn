mod = 998244353
res = 1
cnt = 0
while True:
    if res%mod == 400944928:
        print(cnt)
        exit(0)
    res*=2
    cnt+=1