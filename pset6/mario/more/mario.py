while True:
    height = int(input("specify the height of pyramid between 1 and 8\n"))
    if height >= 1 and height <= 8:
        break

for i in range(height):
    for j in range(2*height +2):
        if (j >= height - 1 -i and j < height) or (j <= height + 2 + i and j > height + 1):
            print("#", end = "")
        else :
            print(" ", end = "")
    print()


