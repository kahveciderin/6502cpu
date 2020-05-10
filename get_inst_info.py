data = []
with open("instruction_data", "r") as f:
    data = f.read().replace("\t", " ").split(" ")
newdata = []
for el in data:
    newdata.append(el)
    if el == '---':
        newdata.append("A")

for x in range(256):
    print(newdata[x * 2 + 1] + ",")