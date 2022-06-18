#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int n; cin >> n;
	int k; cin >> k;
	string s; cin >> s;
	
	int countA = 0;
	int countB = 0;
	int lA = 0;
	int lB = 0;
	int maxA = 0;
	int maxB = 0;
	
	for(int r = 0; r < n; r++){
	    
	    // checking the count of letters
	    if(s[r]=='a') countA++;
	    if(s[r]=='b') countB++;
	    
	    // consider flipping a
	    while(k < countA){
	        if(s[lB]=='a')  countA--;
	        lB++;
	    }
	    
	    maxB = max(maxB,r-lB+1);
	    
	    // consider flipping b
	    while(k < countB){
	        if(s[lA]=='b')  countB--;
	        lA++;
	    }
	    
	    
	    maxA = max(maxA,r-lA+1);
	}
	
	cout << max(maxA,maxB);
	
	return 0;
}
