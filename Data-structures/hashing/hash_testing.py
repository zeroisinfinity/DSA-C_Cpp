class HashTable:

	def __init__(self,size):
		self.size = size
		self.hash_table = self.create_buckets(self.size)
		
	def create_buckets(self,size):
		return [[] for records in range(self.size)]
		
	def print(self):
		print(self.hash_table)
		
	def _hash_func(self,data):
		hash_key = data % self.size
		return hash_key
	
	def insert_data(self,data):
		key = self._hash_func(data)
		self.hash_table[key].append(data) 
		
	def search_key(self,key):
		if self.hash_table[key]:
			print(self.hash_table[key])
		else:
			print("No data saved")

class Node:
	def __init__(self,data):
		self.data = data
		self.next = None
class LinkedList:
	
	def __init__(self,data):
		self.head = Node(data)
	
	def insert_at_start(self,data):
		arg_node = Node()
		
			
		
h1 = HashTable(10)
h1.insert_data(12)
h1.insert_data(13)
h1.insert_data(14)
h1.insert_data(15)
h1.insert_data(25)
h1.insert_data(90)
h1.insert_data(3677)
h1.insert_data(89)
h1.insert_data(80)
h1.search_key(5)
import random
for _ in range(10):
	h1.insert_data(random.randint(1786,222222))
h1.print()
		
