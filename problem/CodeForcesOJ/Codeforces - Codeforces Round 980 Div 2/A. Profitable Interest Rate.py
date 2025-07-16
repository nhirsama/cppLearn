#  A. Profitable Interest Rate
def nhir():
    a, b = map(int, input().split())
    if a > b:
        print(a)
    else:
        print(max(0, a - (b - a)))


if __name__ == "__main__":
    __T = int(input())
    for __ in range(__T):
        nhir()
