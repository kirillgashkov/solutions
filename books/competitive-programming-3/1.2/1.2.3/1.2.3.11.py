with open('input.txt', 'r') as f:
    lines = f.readlines()

for line in lines:
    result = eval(line)
    print(result)
