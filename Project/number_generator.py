import os
import random
num = int(input("Enter you range : "))
numbers = random.sample(range(-10*num, 10 * num), num)

# print(' '.join(str(x) for x in numbers))
print(numbers, "\n")
os.system("make fclean && make && ./push_swap " + ' '.join(str(x)
          for x in numbers) + " | wc -l")
