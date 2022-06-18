#include <bits/stdc++.h>
using namespace std;


void merge(int l, int mid, int r, int *a){
    
    int i = l, j = mid+1, k = l;
    int b[r-l+1];
    
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    
    if(j>r){
    while(i<=mid){
         b[k] = a[i];
            i++;
            k++;
    }
}
    
    if(i>mid){
    while(j<=r){
         b[k] = a[j];
            j++;
            k++;
    }
        
    }
    
    for(int i = l; i <= r; i++)
        a[i] = b[i];
    
}

void mergeSort(int l, int r, int *a){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(l,mid,a);
        mergeSort(mid+1,r,a);
        merge(l,mid,r,a);
    }
}


void printArray(int *a, int n){
    
    cout << "\n";
    
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
        
    cout << "\n";
}

int main() {
	
	int n; cin >> n;
	
	int a[n];
	for(int i = 0 ; i < n ; i++)
	    cin >> a[i];
	
	printArray(a,n);    
	mergeSort(0,n-1,a);
	printArray(a,n);
	
	return 0;
}