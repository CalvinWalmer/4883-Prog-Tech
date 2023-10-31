FINDSCENARIONUMBER = 301

l = 2
c = 0
while(True):
    try:
        if input() == "":
            c = c + 1
            if c == FINDSCENARIONUMBER:
                print(l)
                break
        l = l + 1

    except EOFError:
        break