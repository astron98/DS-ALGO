#include<bits/stdc++.h>
using namespace std;
//KMP algorithm.
void KMPPatternMatch(char* text,char* pat);
void buildLPS(char* pat,int M,int* lps);

void KMPPatternMatch(char* text,char* pat){
	int N = strlen(text);
	int M = strlen(pat);
	
	int lps[M];
	buildLPS(pat,M,lps);	// Building the lps[] array.
	
	int i=0;	// index for text[]
	int j=0;	// index for pat[]
	
	while(i<N){
		if(pat[j]==text[i]){
			i++;j++;
		}
		
		if(j==M){
			// pattern is found
			printf("Pattern is found at %dth index. \n",i-j);
			j = lps[j-1];
		}
		else if(i<N && text[i]!=pat[j]){
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}	
	
void buildLPS(char* pat,int M,int* lps){
	int i=1;
	int j=0;	/*	"j" = length of the longest proper prefix(lps) 
				 *	which is also a proper suffix.	
				 */
	lps[0] = 0;
	while(i<M){
		if(lps[j]==lps[i]){
			j++;
			lps[i] = j;
			i++;
		}
		else{
			if(j!=0)
				j = lps[j-1];
			else{
				lps[i] = 0;
				i++;
			}	
		}
	}
}

int main(){
	/*
	 * eg 1. txt = "AAAAABAAAABA",pat = "AAAA"
	 * eg 2. char text[] = "ABABDABACDABABCABAB";
			 char pat[] = "ABABCABAB";
	 * */
	char text[] = "AAAAABAAAABA";
	char pat[] = "AAAA";
	KMPPatternMatch(text,pat);
	return 0;
}
