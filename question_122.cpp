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
        Transaction tr(INT_MAX,0);
        int allProfit = 0;
        
        /**
         * Do searching the minima and maxima prices, and try to buy stock at each
         * minima and sell it at next minima immediately. This procedure can make
         * sure that will not lost any profit.
         */
        for( int i=0; i < dates ; i++ ){
            if( isMinima( prices, i ) ){
                if( tr.profit > 0 )
                    allProfit += tr.profit;
                tr.setBuyPrice( prices[i] );
                tr.setSellPrice( 0 );
                continue;
            }
            
            if( isMaxima( prices, i ) ){
                tr.setSellPrice( prices[i] );
            }
        }
        
        if( tr.profit > 0 )
            allProfit += tr.profit;
        
        return allProfit;
        
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
