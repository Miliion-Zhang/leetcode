class Solution {
public:
    int numDistinct(string S, string T) {
        int num = 0;
        if( S.size() < T.size() )
            return num;
        
        vector<int> matchStack(T.size(), 0);
        int tp = 0; // Matched char's index in T        
        int sp = 0;
        while(1){
            if( sp >= S.size() ){
                tp--;
                if(tp >= 0)
                    sp = matchStack[tp] + 1;
                else
                    break;
                
            }
            
            if( S[sp] == T[tp] ){
                if( tp == T.size()-1 ){
                    num++;  // find one
                    sp++;
                }
                else{
                    matchStack[tp] = sp;
                    tp++;
                    sp++;
                }
            }
            else{
                sp++;
            }
        }
        
        return num;
    }
};
