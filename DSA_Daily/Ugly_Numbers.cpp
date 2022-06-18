class Solution {
public:
    int nthUglyNumber(int n) {
        int a[n+1];
        a[1]=1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        
        for(int i = 2; i <=n; i++){
            int f2 = 2*a[p2];
            int f3 = 3*a[p3];
            int f5 = 5*a[p5];
            
            int minValue = min(f2,min(f3,f5));
            
            a[i]= minValue;
            
            if(minValue == f2)  p2++;
            if(minValue == f3)  p3++;
            if(minValue == f5)  p5++;
            
        }
        
        return a[n];
    }
};
