class Restaurant():
	def __init__(self,restaurant_name,cuisine_type):
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type
		self.number_served = 0
	def describe_restaurant(self):
		print('This restaurant is called ' + self.restaurant_name)
		print("This restaurant's cuisine_type is " + self.cuisine_type)
	def open_restaurant(self):
		print("The restaurant is opening now!\n")
KFC = Restaurant('KFC','fast food')
KFC.describe_restaurant()
KFC.open_restaurant()
print('KFC have served about ' + str(KFC.number_served) + ' people.\n')
KFC.number_served = 100
print('KFC have served about ' + str(KFC.number_served) + ' people.\n')

class Buffet(Restaurant):
	def __init__(self,restaurant_name,cuisine_type,flavors):
		super().__init__(restaurant_name,cuisine_type)
		self.flavors = flavors

buffet1 = Buffet('ABC','fast',['salt','sweet','bitter'])
print(buffet1.flavors)
