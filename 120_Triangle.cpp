/** Triangle

    Given a triangle, find the minimum path sum from top to bottom. Each step 
    you may move to adjacent numbers on the row below.

    For example, given the following triangle

    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

    Note:
    Bonus point if you are able to do this using only O(n) extra space, where n 
    is the total number of rows in the triangle.

*/


/**
 * This solution must use dynamic programming to avoid over time.
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLevel = triangle.size();
        if(maxLevel < 1)
            return 0;
        
    	/**
         * I use dynamic programming and processing it from bottom to up.
         * Finding the minimum path from bottom to up is Markov Chain,
         * that means if we already have the minimum path from bottom to nodes in level n,
         * and we want to find the minimum path of each node in level n-1, we only need concern
         * about the mimimum path in level n but n+1 / n+2 ...
		 *
         * So what we need to do next is very simple,
         * 1) firstly, we construct an array minPath that holds the minimum path of nodes in level n to bottom.
         *    initialize it with the same values in last line of triangle.
         * 2) secondly, we move up level by level, for example, when we update the m-th node in level n, just
         *    select the min between minPath[m] and minPath[m+1] which already hold the minimum path of nodes
         *    in level n+1, then add it with triangle[n][m] and update minPath[m] using the sum. 
		 *   ( should not worry about ruin the values in minPath when update minPath[m],  because we only change  
         *   minPath[m] and when update minPath[m+1] only need minPath[m+1] and minPath[m+2] ).
         * 3) finally, when reach the top level, minPath[0] is the wanted minimum path from top to bottom.
         */
		int *minPath = new int[ maxLevel ];
		for (int i=0; i<maxLevel ; i++)
		{
			minPath[i] = triangle[maxLevel-1][i];
		}

		for (int n=maxLevel-2; n>=0; n--)
		{
			for (int m=0; m<=n; m++)
			{
				int min = ( minPath[m] < minPath[m+1] ) ? minPath[m] : minPath[m+1] ;
				minPath[m] = min + triangle[n][m];
			}
		}
        
		return minPath[0];
    }
};