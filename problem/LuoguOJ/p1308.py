s =input().upper()
b = input().upper().split()
ptr = -1
cnt = 0
for i in range(len(b)):
    if b[i] == s:
        cnt+=1
        if ptr == -1:
            ptr = i
if ptr == -1:
    print(ptr)
else:
    print(ptr, cnt)