for i in range(256):
    a = hex(i)
    if(i < 10):
        print("case 0x0"+str(i)+":");
    elif(i < 16):
        if(i == 10):
            print("case 0x0a:");
        elif(i == 11):
            print("case 0x0b:");
        elif(i == 12):
            print("case 0x0c:");
        elif(i == 13):
            print("case 0x0d:");
        elif(i == 14):
            print("case 0x0e:");
        elif(i == 15):
            print("case 0x0f:");

    else:
        print("case "+a+":");
    print("\nbreak;");