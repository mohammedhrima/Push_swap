import random
num = int(input("Enter you range :"))
numbers = random.sample(range(10 * num), num)
print(numbers)
