#include <cstdio>
int main()
{
	long int t = 1, a = 0, b = 0, c = 0;
	scanf("%d", &t); 
	for (int i = t + 1; t > 0; t--) {
		scanf("%ld%ld%ld", &a, &b, &c);
		if (a + b > c) printf("Case #%d: true\n", i - t);
		else printf("Case #%d: false\n", i - t); 
	} 
	return 0;
}