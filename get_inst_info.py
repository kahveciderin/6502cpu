data = []
with open("instruction_data", "r") as f:
    data = f.read().replace("\t", " ").split(" ")
newdata = []
for el in data:
    newdata.append(el)
    if el == '---':
        newdata.append("A")
del data
data = []
for el in newdata:
    el = "AM_" + el.replace(",","_").replace("#", "imm")
    data.append(el)
for x in range(256):
    print(data[x * 2 + 1] + ",")