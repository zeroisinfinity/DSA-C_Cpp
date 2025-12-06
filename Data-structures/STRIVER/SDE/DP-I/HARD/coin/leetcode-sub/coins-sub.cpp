class Solution {
public:
    int change(int amount, vector<int>& coins) {
            vector<long long> dp(amount+1,0);
            bool temp = false;
            dp[0] = 1;
            if(amount == 0) return dp[0];
            bool flag = false;
            if(amount%2!=0){
                for(int l : coins){
                 if(l%2==0){ 
                        flag = true;
                 }
                 else{
                    if(l!=amount){
                    flag = false;
                    break;
                    }
                    else temp = true;
                 } 
                }
            }
            if(flag && temp) return 1;
            if(flag) return 0;
         
            for(int cn : coins){//b5 
                    for(int seq = cn ; seq < amount + 1 ; ++seq){//b6
                            dp[seq] += dp[seq - cn];
                    }//b6
            }//b5
            
            return (int)dp[amount];
    }//b3

};

// BEATS 100% IN TIME
// BEATS 93% IN SPACE;
