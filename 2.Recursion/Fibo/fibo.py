MAX = 100
table = [0] * MAX

def fibo(n):
    if n == 0 or n == 1:
        return 1
    else:
        if table[n] == 0:
            table[n] = fibo(n - 1) + fibo(n - 2)
    return table[n]

num = int(input("Enter a number: "))
result = fibo(num)
print(f"The fibo of {num} is {result}.")