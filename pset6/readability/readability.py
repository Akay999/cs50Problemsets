text = input("Enter the text :  ")

letter = 0
words = text.count(" ") + 1
sentence = text.count(".") + text.count("!") + text.count("?")
for char in text:
    if char.isalpha():
        letter += 1

letters = (letter / words)*100
sentences = (sentence / words)*100

grade = round((0.0588 * letters) - (0.296 * sentences) - 15.8)

if(grade < 1):
    print("before grade 1")

elif(grade > 16):
    print("grade 16+")

else:
    print("grade",int(grade))
