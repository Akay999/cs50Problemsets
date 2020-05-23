from sys import argv
from sys import exit
from cs50 import SQL
import csv

db = SQL("sqlite:///students.db")

if len(argv) != 2:
    print("Usage : import.py xyz.csv")
    exit(1)

with open(argv[1]) as file:
    reader = csv.DictReader(file)

    for row in reader:
        names = row["name"].split()
        if len(names) == 3:
            first = names[0]
            middle = names[1]
            last = names[2]
        else :
            first = names[0]
            middle = None
            last = names[1]
        house = row["house"]
        birth = row["birth"]

        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)", first, middle, last, house, birth)

    print("succeed")