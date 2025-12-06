#Function to perform Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

#Function to perform Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

#Function to display top 5 scores
def display_top_five(arr):
    print("Top 5 Scores:")
    for i in range(len(arr) - 1, len(arr) - 6, -1):
        print(f"{len(arr) - i}. {arr[i]}")

#Main Program
percentages = [78.5, 82.3, 67.4, 91.2, 85.9, 74.8, 88.1, 94.5, 69.7, 76.3]

print("Original Percentages:", percentages)

sorted_selection = selection_sort(percentages.copy())
print("\nPercentages after Selection Sort:", sorted_selection)
display_top_five(sorted_selection)

sorted_bubble = bubble_sort(percentages.copy())
print("\nPercentages after Bubble Sort:", sorted_bubble)
display_top_five(sorted_bubble)
