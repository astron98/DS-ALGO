#include<bits/stdc++.h>
using namespace std;

void buildLPS(int *lps, char *pat) {

	int j = 0, i = 1, n = strlen(pat);
	printf("size of pat:%d\n",n);
	while (i < n) {

		if (pat[j] == pat[i]) {
			lps[i++] = j + 1;
			j++;
		}
		else if (pat[j] != pat[i]) {
			if (j > 0)
				j = lps[j - 1];
			else
				lps[i++] = 0;
		}

	}
}

void KMPSearch(char *pat, char *txt) {

	// cout
	int n = strlen(pat), m = strlen(txt);

	int lps[n];
	lps[0] = 0;
	buildLPS(lps, pat);	//longest common prefix which is also a suffix LPS

	int i = 0, j = 0;

	while (i < m) {



		if (pat[j] == txt[i]) {
			i++; j++;

			if (j >= n) {
				cout << "match found at index: " << i - j << "\n";
				j = lps[j-1];
				// continue;
			}
		}
		else {
			if (j > 0) {
				j = lps[j - 1];
			}
			else
				i++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	//scanf("%s", txt);
	//scanf("%s", pat);
	KMPSearch(pat, txt);

	return 0;
}
