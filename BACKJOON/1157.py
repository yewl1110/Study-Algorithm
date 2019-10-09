var_input = input()
arr = list()
i = 0
while i <= ord('Z') - ord('A'):
    arr.append(0)
    i += 1
var_input = var_input.upper()
for char in var_input:
    arr[ord(char) - ord('A')] += 1
max = -1
index = 0
max_index = 0
count = 0
for i in arr:
    if max < i:
        max = i
        max_index = index
        count = 0
    elif max == i:
        count += 1
    index += 1
if count == 0:
    print(chr(max_index + ord('A')), end = '')
else:
    print('?')
