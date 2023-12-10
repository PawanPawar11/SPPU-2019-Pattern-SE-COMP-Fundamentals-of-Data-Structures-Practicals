'''
Write a python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using
1. Selection Sort
2. Bubble Sort and display top five scores
'''
def SelectionSort(arr,n):
	for i in range(n):
		Min=i;
		for j in range(i+1,n):
			if(arr[j]<arr[Min]):
				Min=j
		temp=arr[i]
		arr[i]=arr[Min]
		arr[Min]=temp
	print(arr)				
	
def BubbleSort(arr,n):
	for i in range(n-1):
		for j in range(n-i-1):
			if(arr[j]>arr[j+1]):
				temp=arr[j]
				arr[j]=arr[j+1]
				arr[j+1]=temp
	for i in range(len(arr)-5, len(arr),+1):
		print(arr[i])			
print("\nSorting FE Students Percentage : ")
print("\nEnter the number of students: ")
n=int(input())
array=[]
i=0
for i in range(n):
	print("\nEnter Percentage of Student", i+1)
	marks=float(input())
	array.append(marks)

print("Original Lis of Percentage\n")
print(array)

print("\nSorted List of Percentage is")
SelectionSort(array,n)

print("\nBubble Sorted Top 5 Scores are: ")
BubbleSort(array,n)