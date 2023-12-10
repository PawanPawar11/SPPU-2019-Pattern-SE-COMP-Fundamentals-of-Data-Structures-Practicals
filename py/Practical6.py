'''
Write a Python program to store first year percentage of students in array. 
Write function for sorting array of floating point number ascending order using Quick Sort. 
'''
a=[]
n = int(input("Enter no of elements : "))
print("Enter elements : ")
for i in range(0,n):
	elements=float(input())
	a.append(elements)
print(a)

def Top(a):
	for i in range(1,n):
		for j in range(n-1):
			if(a[j]<a[j+1]):
				a[j],a[j+1]=a[j+1],a[j]
	print("Top 5 marks : ")
	for k in range(0,5):
		print(a[k])

def quickSort(a,start,end):
	if start >= end:
		P=partition(a,start,end)
		quickSort(a,start,P-1)
		quickSort(a,P+1,end)
	print(a)

def partition(a,start,end):
	pivot=a[start]
	i=start+1
	j=end
	while True:
		while(i<j and a[i]<pivot):
			i=i+1
		while(j>i and a[j]>pivot):
			j=j-1
		if(i<j):
			a[i],a[j]=a[j],a[i]
		else:
			break
	a[j],pivot=pivot,a[j]
	return j
b=True
while(b):
	print("************* MENU **************")
	print("1.For top 5 marks\n2.For quick sorted array\n3.For exit")
	choice=int(input("Enter your choice : "))
	if(choice==1):
		Top(a)
	elif(choice==2):
		quickSort(a,0,n-1)
	elif(choice==3):
		print("*********** THANK YOU ************")
		b=False
	else:
		print("Your choice is not valid. Please enter a valid choice")