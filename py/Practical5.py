'''
Write a python program to maintain club members, sort on roll numbers in ascending order. 
Write function "Ternary Search" to search whether particular student is member of club or not. 
'''
def accept_roll():
    num_students = int(input("Enter the number of students: "))
    roll_numbers = [int(input(f"Enter Roll Number of Student {i + 1}: ")) for i in range(num_students)]
    return roll_numbers

def insertion_sort(roll_numbers):
    for i in range(1, len(roll_numbers)):
        temp = roll_numbers[i]
        j = i - 1
        while j >= 0 and temp < roll_numbers[j]:
            roll_numbers[j + 1] = roll_numbers[j]
            j -= 1
        roll_numbers[j + 1] = temp
    return roll_numbers

def recursive_ternary_search(roll, left, right, roll_to_find):
    if right >= left:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if roll[mid1] == roll_to_find:
            return mid1
        if roll[mid2] == roll_to_find:
            return mid2

        if roll_to_find < roll[mid1]:
            return recursive_ternary_search(roll, left, mid1 - 1, roll_to_find)
        elif roll_to_find > roll[mid2]:
            return recursive_ternary_search(roll, mid2 + 1, right, roll_to_find)
        else:
            return recursive_ternary_search(roll, mid1 + 1, mid2 - 1, roll_to_find)
    return -1

def menu():
    roll_numbers = []
    sorted_roll_numbers = []

    while True:
        print("\n---------------------MENU---------------------")
        print("1. Accept Student Roll Numbers")
        print("2. Display the Roll Numbers of Students")
        print("3. Sort Roll Numbers")
        print("4. Perform Recursive Ternary Search")
        print("5. Exit")

        choice = int(input("Enter your choice (from 1 to 5): "))

        if choice == 1:
            roll_numbers = accept_roll()
        elif choice == 2:
            print(*roll_numbers, sep='\n')
        elif choice == 3:
            sorted_roll_numbers = insertion_sort(roll_numbers[:])
            print("Sorted Roll Numbers:")
            print(*sorted_roll_numbers, sep='\n')
        elif choice == 4:
            roll_to_find = int(input("Enter the Roll Number to be searched: "))
            index = recursive_ternary_search(sorted_roll_numbers, 0, len(sorted_roll_numbers) - 1, roll_to_find)
            if index != -1:
                print(f"The Roll Number {roll_to_find} is found at position {index + 1}")
            else:
                print(f"Roll Number {roll_to_find} not found!")
        elif choice == 5:
            print("Thanks for using this program!")
            break
        else:
            print("Invalid choice!")

menu()
