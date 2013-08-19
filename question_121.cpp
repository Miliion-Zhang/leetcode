
#include <limits.h>

struct Transaction {
    int buyPrice;
    int sellPrice;
    int profit;
    Transaction(int buy, int sell): buyPrice(buy), sellPrice(sell) {
        profit = sell - buy;
    }
    
    void setBuyPrice(int buy){
        buyPrice = buy;
        updateProfit();
    }
    
    void setSellPrice(int sell){
        sellPrice = sell;
        updateProfit();
    }
    
    void updateProfit(){
        profit = sellPrice - buyPrice;
    }
    
    void copy( const Transaction src ){
        buyPrice = src.buyPrice;
        sellPrice = src.sellPrice;
        updateProfit();
    }
};

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dates = prices.size();
        if( dates < 2 )
            return 0;
        
        // Initialze transaction with highest buy prices and lowest cell prices.
        Transaction best(INT_MAX,0), cadidate(INT_MAX,0);
        
        /**
         * Do searching the best transaction.
         * If the prices is minima, then it will be buyPrice of cadidate transaction,
         * and reset cadidate's sellPrice to 0, then try to find a maxima in prices
         * to sell the stock both in cadidate / best if current maxima is larger than
         * it's privious sellPrice.
         * 
         * If we find a cadidate transaction and it's profits is higher than best currently,
         * then we will replace best with it.
         */
        for( int i=0; i < dates; i++ ){
            if( isMinima( prices, i ) ){
                if( prices[i] < cadidate.buyPrice ){
                    cadidate.setBuyPrice( prices[i] );
                    cadidate.setSellPrice( 0 );
                    continue;
                }
            }
            
            if( isMaxima( prices, i ) ){
                if( prices[i] > best.sellPrice )
                    best.setSellPrice( prices[i] );
                    
                if( prices[i] > cadidate.sellPrice ){
                    cadidate.setSellPrice( prices[i] );
                    if( cadidate.profit > best.profit )
                        best.copy( cadidate );
                }
            }
        }
        
        return best.profit > 0 ? best.profit : 0 ;
        
    }
    
    /**
     * Check if the given value is minima in vector
     */
    inline bool isMinima(vector<int> &vec, int index){
        int size = vec.size();
        if( index < 0 || index > size-1 )
            return false;
        
        if( size == 1 )
            return true;
            
        if( index == 0 )
            return vec[0] <= vec[1];
        
        if( index == size-1 )
            return vec[index-1] >= vec[index];
        
        return ( vec[index-1] >= vec[index] ) && ( vec[index+1] >= vec[index] );
    }
    
    /**
     * Check if the given value is maxima in vector
     */
    inline bool isMaxima(vector<int> &vec, int index){
        int size = vec.size();
        if( index < 0 || index > size-1 )
            return false;
        
        if( size == 1 )
            return true;
            
        if( index == 0 )
            return vec[0] >= vec[1];
        
        if( index == size-1 )
            return vec[index-1] <= vec[index];
        
        return ( vec[index-1] <= vec[index] ) && ( vec[index+1] <= vec[index] );
    }
};



/**
 * Here is a much more simpler version, the principle is simillar but the code
 * is forthright.
 */
 class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * Only can sell it after buying.
         * 
         *  This solution will use O(1) space and O(n) time in all.
         */
        
        int dates = prices.size();
        if( dates < 2 )
            return 0;
        
        int minIndex = 0;	// the min price's index in prices
        int maxDiff = 0;	// the max profit currently.
        for(int i=1; i<dates ; i++){
            if( prices[i] < prices[minIndex] )
                minIndex = i;
            
            int diff = prices[i] - prices[minIndex];
            if( diff > maxDiff )
                maxDiff = diff;
        }
        
        return maxDiff;
    }
 };
