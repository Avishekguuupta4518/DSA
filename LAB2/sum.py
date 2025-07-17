def sum(n):
    if n == 1:
        return 1
    else:
        return n + sum(n - 1)

num = int(input("Enter a number: "))
result = sum(num)
print(f"The sum of {num}  is {result}.")