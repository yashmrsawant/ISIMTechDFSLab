def permute(n = 0, prefix = [], suffix = []):
	if(len(prefix) == n):
		for i in prefix:
				print(i)
		print()
	else:
		for i in range(len(suffix)):
			newPrefix = []
			for j in prefix:
				newPrefix.append(j)
			newPrefix.append(suffix[i])
			newSuffix = []
			if(i < (len(suffix) - 1)):
				for k in range(0, i):
					newSuffix.append(suffix[k])
				for k in range(i + 1, len(suffix)):
					newSuffix.append(suffix[k])
			else:
				newSuffix = []
			permute(n, newPrefix, newSuffix)
				
suffix = ['a', 'b', 'a']	
permute(len(suffix), [], suffix)