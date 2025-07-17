def GCD(a, b):
    if b == 0:
        return a
    else:
        return GCD(b, a % b)

num1 = int(input("Enter a number1: "))
num2 = int(input("Enter a number2: "))
result = GCD(num1, num2)
print(f"The GCD of {num1} and {num2} is {result}.")