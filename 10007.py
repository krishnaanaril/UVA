while 1:
	n = int(input(), 10)
	if n==0:
		break
	ans = 1
	for i in range(2*n, n+1, -1):
		ans  = ans*i
	print(ans)
 
