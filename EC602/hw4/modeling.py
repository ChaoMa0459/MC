# Copyright 2017 Chao Ma mc163@bu.edu

class Polynomial():
	"My Polynomial"
#	pass
	def __init__(self, poly = []):
		"constructor"
		self.l = len(poly)
		self.coef = poly[:]
		self.power = []
		for i in range (self.l):
			self.power.append(self.l - i - 1)
		
	def __add__(self, poly):
		"addition"
		result = Polynomial([])
		for i in range(self.l):
			result[self.power[i]] += self.coef[i]
		for i in range(poly.l):
			result[poly.power[i]] += poly.coef[i]
		return result
		
	def __sub__(self, poly):
		"substraction"
		result = Polynomial([])
		for i in range(self.l):
			result[self.power[i]] += self.coef[i]
		for i in range(poly.l):
			result[poly.power[i]] -= poly.coef[i]
		return result

	def __mul__(self, value):
		"multiplication"
		result = Polynomial([])
		for i in range(self.l):
			for j in range(value.l):
				loc = self.power[i]+value.power[j]
				tar = self.coef[i]*value.coef[j]
				if result.l == 0:
					result.coef.append(tar)
					result.power.append(loc)
					result.l += 1
				else:
					for k in range(result.l):
						if loc>result.power[0]:
							result.power.insert(0,loc)
							result.coef.insert(0,tar)
							result.l += 1
							break
						elif loc>=result.power[result.l - 1]:
							for b in range(result.l):
								if loc>result.power[b]:
									result.coef.insert(b,tar)
									result.power.insert(b,loc)
									result.l += 1
									break
								elif loc==result.power[b]:
									result.coef[b] += tar
									break
							break
						else:
							result.power.append(loc)
							result.coef.append(tar)
							result.l += 1 
							break

#		else:
#			for i in range(self.l):
#			result.coef.append(self.coef[i]*value)
#			result.power.append(self.power[i])
#			result.l += 1
		return result

	def __eq__(self, poly):
		"equality"
		if self.l != poly.l:
			return False
		for i in range(self.l):
			if (self.power[i] != poly.power[i]) or (self.coef[i] != poly.coef[i]):
				return False
		return True

	def eval(self, value):
		"evaluation"
		result = 0
		for i in range(self.l):
			result += value ** self.power[i] * self.coef[i]
		return result

	def deriv(self):
		"derivative"
		result=Polynomial([])
		result.l=self.l
		result.coef=self.coef
		result.power=self.power
		try:
			loc=result.power.index(0)
			result.power.pop(loc)
			result.coef.pop(loc)
			result.l=result.l-1
		except:
			pass
		for i in range(result.l):
			result.coef[i]=result.coef[i]*result.coef[i]
			result.power[i]=result.power[i]-1
		return result

	def __getitem__(self, index):
		try:
			#get the power value of index in self.power
			loc = self.power.index(index)
			return self.coef[loc]
		except:
			return 0  
		    
	def __setitem__(self, key, item):
		flag = 0
		for i in range(self.l):
			if self.power[i] == key:
				loc = i
				flag = 1
				break
			if self.power[i] < key:
				loc = i
				flag = 2
				break
		if flag == 1:
	 		self.coef[loc] = item
		elif flag == 2:
	    		self.coef.insert(loc,item)
	    		self.power.insert(loc,key)
	    		self.l += 1
		# key < all power, negative
		else:
	    		self.coef.append(item)
	    		self.power.append(key)
	    		self.l += 1

	def __radd__(self,value):
		return self.__add__(value)

	def __rsub__(self,value):
		return self.__sub__(value)

	def __rmul__(self,value):
		return self.__mul__(value)

def main():
	a = Polynomial([1,2,3])
	b = Polynomial([1,2,3])
	print(a.coef)
	print(a.power)
	c = a - b
	print(c.coef)
	print(c.power)
	print(a.eval(2))
	print(a == c) 
	print(a.deriv().coef)

if __name__ == "__main__":
	main()
