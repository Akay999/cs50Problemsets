from sys import argv
from sys import exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("Usage: python roster housename")
    exit(1)

db = SQL("sqlite:///students.db")

names = db.execute("SELECT DISTINCT(house) FROM students;")
house = []

for row in names:
    house.append(row["house"])


if argv[1] in house:
    re = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])
else :
    print("no")

for row in re:
    if row["middle"] == None:
        print(row["first"], row["last"], ", born", row["birth"])
    else :
        print(row["first"] , row["middle"] , row["last"] , ", born" , row["birth"])