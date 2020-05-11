from functools import reduce
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
jumping_opcodes = [
    "BCC",
    "BCS",
    "BEQ",
    "BMI",
    "BNE",
    "BPL",
    "BRK",
    "BVC",
    "BVS",
    "JMP",
    "JSR",
    "RTI",
    "RTS"
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
datasheet_entries_instrs = list(map(lambda x: list(filter(lambda y: len(y) > 0, x.strip().split(" "))), list(filter(lambda x: x.strip().split(" ")[0] in valid_instrs, rawhtml))))
datasheet_entries = map(lambda x: x.strip().split(" ")[3:], list(filter(lambda x: x.strip().split(" ")[0] == "<span", rawhtml)))
case_info = [list() for _ in range(256)]
cases = ""
instr_explanations = {}
for entry in datasheet_entries:
    #oplens[int(entry[-3], base=16)] = int(entry[-2])

    #cases += "// " + entry[1] ++ " - " 
    instr_explanations[entry[0][9:12]] = reduce(lambda x, y: x + " " + y, entry[2:], "")
datasheet_entries_instrs.sort(key=lambda x: x[-3])
for entry in datasheet_entries_instrs:
    #cases += "// " + entry[1] + " (" + entry[0] + ") - " + instr_explanations[entry[1]] + "\ncase 0x" + entry[-3] + ": "
    cases += """
        // {instr_name} ({instr_addmode}) - {explanation}
        case 0x{hexcode}:

        break;
        """.format(instr_name=entry[1], instr_addmode=entry[0], explanation=instr_explanations[entry[1]], hexcode=entry[-3])
print(cases)