from cs50 import get_float

change = get_float("Change owned\n")

change = int(change*100)

count = 0
if change >= 25:
    count = change // 25
    change = change % 25

if change >= 10:
    count += change // 10
    change  = change % 10

if change >= 5:
    count += change // 5
    change = change %5

if change >= 1:
    count += change

print(count)