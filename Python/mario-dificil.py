while True:
    n = int(input('Altura: '))
    if n >=1 and n <=8:
        break
for i in range(n):
    print(" "* (n-i), end="")
    print("#"*(i + 1), end="")
    print(" "* 2, end="")
    print("#" * (i + 1), end="")
    print(end="\n")