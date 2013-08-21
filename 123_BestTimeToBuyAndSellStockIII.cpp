/** Best Time to Buy and Sell Stock III

    Say you have an array for which the ith element is the price of a given
    stock on day i.

    Design an algorithm to find the maximum profit. You may complete at most
    two transactions.

    Note:
    You may not engage in multiple transactions at the same time (ie, you must
    sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * Split this question to two parts, that means for the given day i,
         * step1: calculate the max profit from beginning to now at most one transaction,
         * step2: calculate the max profit from now to end at most one transaction,
         * step3: get sum of these two profits of each day, then find the maximum as the 
         *        max profit we can get at mosttwo transactions
         * 
         * We can reduce computing time by record the max profit to current day to an
         * array other than calculate it each time. Meanwhile, we can record the max
         * profit from now to another array by searching the prices from ending to now,
         * this also can save a lot of time.
         * ps: we can reduce space by merging these two arrays to just one, because we
         *     only need their sum, we can update the array in second step after first
         *     step.
         * 
         * step 1 and 2 both need O(n) space and O(n) time, and step 3 only need O(1) space
         * and O(n) time, so this solution will use O(n) space and O(n) time in all.
         */
        
        int dates = prices.size();
        if( dates < 2 )
            return 0;
        
        vector<int> curMaxProfit(dates, 0);
        vector<int> futureMaxProfit(dates, 0);
        
        getCurMaxProfitArray( prices, curMaxProfit );
        getFutureMaxProfitArray( prices, futureMaxProfit );
        
        int maxDiff;
        for( int i=0; i<dates; i++ ){
            int profit = curMaxProfit[i] + futureMaxProfit[i];
            if( profit > maxDiff )
                maxDiff = profit;
        }
        
        return maxDiff;
    }
    
    /**
     * For day i, calculate current max profit from beginning to now, and save it to curMaxProfit[i].
     * Notice that the size of prices must larger than 1; and the curMaxProfit is same size and
     * initialized with 0.
     */
    void getCurMaxProfitArray(vector<int> &prices, vector<int> &curMaxProfit){
        int dates = prices.size();
        int minIndex = 0;	// the min price's index in prices
        int maxDiff = 0;	// the max profit currently.
        curMaxProfit[0] = maxDiff;
        for(int i=1; i<dates ; i++){
            if( prices[i] < prices[minIndex] )
                minIndex = i;
            
            int diff = prices[i] - prices[minIndex];
            if( diff > maxDiff )
                maxDiff = diff;
            
            curMaxProfit[i] = maxDiff;
        }
    }
    
    /**
     * For day i, calculate future max profit from now to end, and save it to futureMaxProfit[i].
     * Notice that the size of prices must larger than 1; and the futureMaxProfit is same size and
     * initialized with 0.
     */
    void getFutureMaxProfitArray(vector<int> &prices, vector<int> &futureMaxProfit){
        int dates = prices.size();
        int maxIndex = dates-1;	// the max price's index in prices
        int maxDiff = 0;				// the max profit currently.
        futureMaxProfit[dates-1] = 0;
        for( int i=dates-2 ; i > 0 ; i-- ){
            if( prices[i] > prices[maxIndex] )
                maxIndex = i;
                
            int diff = prices[maxIndex] - prices[i];
            if( diff > maxDiff )
                maxDiff = diff;
            
            futureMaxProfit[i] = maxDiff;
        }
        
    }
};