marks = []
absent_count = 0

total_students = int(input("Enter total number of students in class: "))
print("Enter -1 for absent student")

for i in range(total_students):
    score = int(input("Enter Marks obtained: "))
    if score != -1:
        marks.append(score)
    else:
        absent_count += 1

average = sum(marks) / (total_students - absent_count)
print("Average marks obtained by the class:", average)

print("Total number of absent students:", absent_count)

highest = max(marks)
print("Highest marks obtained in the class:", highest)

lowest = min(score for score in marks if score != -1)
print("Lowest marks obtained in the class:", lowest)

max_marks_freq = marks.count(highest)
print("Number of students who scored the maximum marks:", max_marks_freq)
