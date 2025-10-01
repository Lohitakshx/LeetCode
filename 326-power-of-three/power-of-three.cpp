class Solution {
public:
    bool loki(int n){
        if(n==1) return true;
        if(n<=0 || n%3!=0) return false;
        
        return loki(n/3);
    }
    bool isPowerOfThree(int n) {
        return loki(n);
    }
};