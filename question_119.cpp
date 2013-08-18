class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rowIndex += 1;  // I'm familar with the index from 1, but the input rowIndex is from 0...
        
        if( rowIndex < 1 ){
            vector<int> ans;
            return ans;
        }
        
        vector<int> firstRow(1,1);
        vector<int> secondRow(2,1);
        if( rowIndex == 1 )
            return firstRow;
        if( rowIndex == 2 )
            return secondRow;
        
        int lastVal = 1;
        vector<int> ans = secondRow;
        int curRowNum = 3;
        while( curRowNum <= rowIndex ){
            for(int i=1; i < curRowNum-1; i++){
                int tmpLast = ans[i];
                ans[i] = lastVal + ans[i];
                lastVal = tmpLast;
            }
            ans.push_back(1);
            curRowNum++;
        }
        
        return ans;
    }
};