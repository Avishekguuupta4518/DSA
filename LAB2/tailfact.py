def tailfact(a, n):
    if n == 0:
        return a
    else:
        return tailfact(n * a, n - 1)

num = int(input("Enter a number: "))
result = tailfact(1, num)
print(f"The factorial of {num} is {result}.")