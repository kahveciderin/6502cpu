valid_instrs = [
    "accumulator",
    "absolute",
    "absolute,X",
    "absolute,Y",
    "(indirect,X)",
    "(indirect),Y",
    "immidiate",
    "implied",
    "indirect",
    "relative",
    "zeropage",
    "zeropage,X",
    "zeropage,Y"
]


data = []
with open("instruction_data", "r") as f:
    data = f.read().replace("\t", " ").split(" ")
newdata = []
for el in data:
    newdata.append(el)
    if el == '---':
        newdata.append("NONEXIST")
del data
inmodes = []
for x in range(256):
    inmodes += newdata[x * 2 + 1]
rawhtml = []
with open("raw_instsize_data.html") as f:
    rawhtml = f.readlines()
#list(map(lambda x: print(x.split(" ")[0] + ","), rawhtml))
datasheet_entries = map(lambda x: list(filter(lambda y: len(y) > 0, x.strip().split(" "))), list(filter(lambda x: x.strip().split(" ")[0] in valid_instrs, rawhtml)))
oplens = [0] * 256
for entry in datasheet_entries:
    oplens[int(entry[-3], base=16)] = int(entry[-2])
print(oplens)