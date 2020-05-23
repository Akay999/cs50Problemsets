while True:
    height = int(input("specify the height of pyramid between 1 and 8\n"))
    if height >= 1 and height <= 8:
        break

for i in range(height):
    for j in range(height):
        if j >= height -1 -i:
            print("#", end = "")
        else :
            print(" ", end = "")

    print()

