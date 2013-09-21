/** Edit Distance

Given two words word1 and word2, find the minimum number of steps
required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    /**
      * Using two dimension DP method.
      * 
      * see the following blog for more details:
      * http://blog.unieagle.net/2012/09/19/
      */
    int minDistance(string word1, string word2) {
        // why should +1? see defination of `distance`
        int rows = word1.size()+1;
        int cols = word2.size()+1;
        
        // distance[i][j] means the edit distance from word1 with 
        // length = i to word2 with length = j
        vector<vector<int> > distance;
        for( int i = 0; i < rows; i++ ){ // initialize distance and first column
            vector<int> row(cols, 0);
            row[0] = i;
            distance.push_back(row);
        }
        
        for( int j = 0; j < cols; j++ ){ // initialize first row
            distance[0][j] = j;
        }
        
        for( int i = 1; i < rows; i++ ){
            char ci = word1[i-1];
            for( int j = 1; j < cols; j++ ){
                char cj = word2[j-1];
                if( ci == cj ){
                    distance[i][j] = distance[i-1][j-1];
                }
                else{
                    // replace ci with cj
                    int len1 = distance[i-1][j-1] + 1;
                    
                    //if we add cj to the end of word1[0,i), then from the edit distance of 
                    // word1[0,i) to word2[0, j -1), we can conclude follow distance
                    int len2 = distance[i][j-1] + 1;
                    
                    //if we delete ci from word1[0,i), and we know the distance
                    // from word1[0,i-1) to word2[0,j), then will be:
                    int len3 = distance[i-1][j] + 1;
                    
                    int minLen = min(len1, len2);
                    minLen = min(minLen, len3);
                    distance[i][j] = minLen;
                }
            }
        }
        
        return distance[rows-1][cols-1];
    }
};
