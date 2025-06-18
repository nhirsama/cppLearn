print(2, end='')
for i in range(2):
    print()
    print(1, 10 ** 5)
    for j in range(10 ** 5):
        print(0b111111, end='')
        print(('' if j == 10 ** 5 - 1 else ' '), end='')
print()