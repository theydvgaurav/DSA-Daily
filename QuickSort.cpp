#include<bits/stdc++.h>

using namespace std;


int partition(int l, int r, int *a){
    int i = l, j = r, piv = a[l];

    while(i<j){
        while(a[i] <= piv) i++;
        while(a[j] > piv) j--;

        if(i<j){
            swap(a[i],a[j]);
        }
    }

    if(i>j){
        swap(a[j],a[l]);
    }

    return j;

}

void quick_Sort(int l, int r, int *a){
    if(l<r){
        int piv = partition(l,r,a);
        quick_Sort(l,piv-1,a);
        quick_Sort(piv+1, r,a);
    }
}


void printArray(int *a, int n){
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}

int main(){
    int n; cin >> n;

    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    quick_Sort(0,n-1,a);
    printArray(a,n);

    return 0;
}