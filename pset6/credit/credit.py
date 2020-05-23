from cs50 import get_int
from sys import exit

h = get_int("Enter the number:   ")
s = str(h)
l = len(s)
sum = 0
count = 0

for i in s[::-1]:
    i = int(i)
    if count % 2 != 0:
        i *= 2
        if i > 9:
            i -= 9
            sum += i
        else :
            sum += i
        count += 1
    else :
        sum += i
        count += 1

if sum % 10 != 0:
    print("Invalid card")
    exit(1)

check = s[0:2]

if (check in ["34", "37"]) and (l == 15):
    print("AMEX")

elif (check in ["54", "51", "52", "53", "55"]) and (l == 16):
    print("MASTERCARD")

elif (s[0] == "4") and (l in [13, 16]):
    print("VISA")

else:
    print("unknown")