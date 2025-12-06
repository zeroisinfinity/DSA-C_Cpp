def iterative_bubble_sort(array):
	for limiter in range(len(array)-1):
		swap_flag = False
		for cf in range( 0 , len(array) - limiter - 1 ):
			if array[ cf ] > array[ cf + 1 ]:
				array[ cf ] , array[ cf + 1 ] = array[ cf + 1 ] , array[ cf ]
				swap_flag = True
		if swap_flag == False:
			break
	return array
	
print(iterative_bubble_sort([9,8,7,6,5,4,3,2,1,0]))
			
			
			
	
