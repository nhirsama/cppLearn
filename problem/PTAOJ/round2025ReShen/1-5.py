n,m = map(int,input().split())
cnt = 0
ans:str
for _ in range(n):
    s = input()
    if not "qiandao" in s and not "easy" in s:
        m-=1
        if m == -1 :ans = s
if m > -1:
    print("Wo AK le")
else :print(ans)