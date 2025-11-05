class Solution {
public:
    int mySqrt(int x) {
        if (x == 1|| x==2) return 1;
        for(long long i = 1; i< x; i++){
            if(i*i==x) return i;
            if(i*i>x) return i-1;
        }
        return 0;
    }
};