n=input()
m=input()
e=[]
for _ in xrange(m):
	cl=raw_input().split(',')
	for i in xrange(len(cl)):
		p=int(cl[i][-1])
		if(cl[i][0]=='~'):p=p*-1
		cl[i]=p
	e.append(cl)

print n
print m
for i in xrange(m):
	print len(e[i])
	for j in xrange(len(e[i])):
		print e[i][j],
	print

