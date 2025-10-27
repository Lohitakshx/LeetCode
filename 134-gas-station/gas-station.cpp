class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currGas = 0;
        int start = 0;
        int max1 = 0;
        int max2 = 0;
        for(int i =0; i< gas.size(); i++){
            currGas += (gas[i]-cost[i]);
            max1+=gas[i];
            max2+=cost[i];
            if(currGas < 0){
                currGas=0;
                start = i+1;
            }
        }
        if(max1<max2) return -1;
        return start;
    }
};