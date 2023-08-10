class Solution {
    
public:
    int reachNumber(int target) {
        target = abs(target);
        int steps = 0;
        int pos = 0;
        
        while(pos < target) {
            pos += steps;
            steps++;
        }
        
        while((pos - target) % 2) {
            pos += steps;
            steps++;
        }
        
        return steps - 1;
    }
};