#include <cstdio>
#define scanf scanf_s

int main()
{
	int n = 0, a = 0, z = 0, count = 0, output[6] = { 0 };
	float b = 0;
	scanf("%d", &n);

	for (int i = 0; i<n; i++)
	{
		scanf("%d", &a);
		if (a % 5 == 0 && a % 2 == 0)  output[1] = output[1] + a;

		if (a % 5 == 1){
			if (z == 0) { 
				output[2] = output[2] + a; z = 1; 
			}
			else {
				output[2] = output[2] - a; z = 0; 
			}
			if (i == n - 1 && output[2] == 0) output[2] = -1000;
		}

		if (a % 5 == 2) output[3]++;

		if (a % 5 == 3){
			count++; b = b + a;
			output[4] = b;
		}

		if (a % 5 == 4 && a > output[5]) output[5] = a;

		if (i == n - 1)
			for (int i1 = 1; i1 < 6; i1++){
				if (output[i1] == 0) printf("N");
				else{
					if (output[2] == -1000) printf("0");
					else{
						if (i1 == 4) printf("%.1f", b / count);
						else printf("%d", output[i1]);
					}
				}
				if (i1 != 5) printf(" ");
			}
	}
	return 0;
}