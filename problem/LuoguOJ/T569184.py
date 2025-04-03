import sys
s = sys.stdin.readline()
arr = []
for line in sys.stdin:
    line = line.strip()
    if line:
        arr.append(int(line))
cnt = 0
for num in reversed(arr):
    if num == 1:
        cnt += 1
    else:
        break
print(cnt)