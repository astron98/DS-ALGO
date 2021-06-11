#include <bits/stdc++.h>

using namespace std;

void prime(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	for (int p = 2; p * p < n; p++)
	{

		if (prime[p] == true)
		{
			for (int i = p * p; i < n; i = i + p)
				prime[i] = false;
		}
	}

	for (int p = 2; p < n; p++)
		if (prime[p])
			printf("%d ", p);
}

int main()
{
	int n = 0;
	printf("Enter the range: ");

	scanf("%d", &n);
	prime(n);

	return 0;
}
