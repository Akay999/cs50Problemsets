from sys import argv, exit
import csv

#checking for the correct arguments
if len(argv) != 3:
    print("Usage - python dna.py 'name of csv' 'name of txtfile'")
    exit(1)

#defining an empty list of str
dna_str = []

#defining an empty list of max count of str sequence
max = []

#opening the .csv file
with open (argv[1]) as file:
    reader = csv.DictReader(file)
    dnadatabase = list(reader)

#creating headers
dna_str = list(dnadatabase[0].keys())
dna_str.remove('name')



#opening the unknown sequence database
f = open(argv[2], "r")
dna = f.read()


dictstr = dict.fromkeys(dna_str, 0)
maxcount = 0
for i in dna_str:
    maxcount = 0
    for j in range(len(dna)):
        k = j
        count = 0
        while dna[k :k+len(i) ] == i:
            k += len(i)
            count += 1
        if maxcount < count:
            maxcount = count
    dictstr.update({i : str(maxcount)})

matchfound = False

#comparing the sequence with the database
for row in dnadatabase:
    match = 0
    for i in dna_str:
        if row[i] != dictstr[i]:
            break
        else:
            match += 1

    if match == len(dna_str):
        print(row['name'])
        matchfound = True
        break

if matchfound != True:
    print("Unknown")

