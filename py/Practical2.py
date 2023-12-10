'''
Python program to compute 
a> To display word with longest length 
b> Frequency 
c> Palindrome 
d> Appear first
'''

def longest_word_and_length(string):
    words = string.split()
    longest = max(words, key=len)
    print("The longest word in the string is", longest, "Its length is", len(longest))

def char_frequency(string, char):
    count = string.count(char)
    print("The frequency of occurrence of", char, "in the string is", count)

def palindrome_check(string):
    words = string.split()
    palindromes = [word for word in words if word == word[::-1]]
    for palindrome in palindromes:
        print(palindrome, "is a palindrome")

def substring_index(string, substring):
    index = string.find(substring)
    if index != -1:
        print("The first appearance of the substring in the string is at index", index)
    else:
        print("The substring is not found in the string")

def word_counts(string):
    words = string.split()
    counts = {}
    for word in words:
        counts[word] = counts.get(word, 0) + 1
        print(word, ",", counts[word])

string_input = input("Enter your string: ")

while True:
    print("*_*_*_*_*_*_*_*_*_MENU_*_*_*_*_*_*_*_*_*")
    print("Enter your choice to perform the following string functions:")
    print("1. Print the LONGEST word and its LENGTH")
    print("2. Find a character's OCCURRENCE in the string")
    print("3. Find PALINDROMES in the string")
    print("4. Find INDEX of a SUBSTRING")
    print("5. Print ALL the WORDS and their COUNT")
    print("6. Exit the program")
    
    choice = input("Enter your choice: ")

    if choice == "1":
        longest_word_and_length(string_input)
    elif choice == "2":
        char_input = input("Enter a character: ")
        char_frequency(string_input, char_input)
    elif choice == "3":
        palindrome_check(string_input)
    elif choice == "4":
        substring_input = input("Enter the substring to search: ")
        substring_index(string_input, substring_input)
    elif choice == "5":
        word_counts(string_input)
    elif choice == "6":
        print("You have terminated the program.")
        break
    else:
        print("You have provided a wrong option.")
