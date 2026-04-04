#  P10415 [蓝桥杯 2023 国 A] 切割
import math

w, h = map(int, input().split())

Gcd = math.gcd(w, h)
if Gcd != 1:
    for i in range(2, int(math.sqrt(w * h // Gcd)) + 10):
        if w % i == 0 and h % i == 0:
            print((w // i) * (h // i))
            exit(0)
    print((w // Gcd) * (h // Gcd))
else:
    print(0)
