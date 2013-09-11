/** Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a
container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if( size < 2 )
            return 0;
        
        int maxv = 0;
        vector<int> harray;
        vector<int> xarray;
        harray.push_back( height[0] );
        xarray.push_back( 0 );
        for( int i = 1; i < size; i++ ){
            if( height[i] > harray.back() ){
                for( int j = 0; j < harray.size(); j++ ){
                    int w = i - xarray[j];
                    int area = harray[j] * w;
                    maxv = (area > maxv) ? area : maxv;
                }
                
                harray.push_back( height[i] );
                xarray.push_back( i );
            }
            else{   // should not push current height to harray
                for( int j = 0; j < harray.size(); j++ ){
                    int w = i - xarray[j];
                    int h = min( harray[j], height[i] );
                    int area = h * w;
                    maxv = (area > maxv) ? area : maxv;
                }
            }           
            
        }
        
        return maxv;
    }
};

/** a O(n) solution using greedy algorithm
 * see the following for more details:
 * 类似于2Sum的思想，两边设一个指针，然后计算area，如果height[i] <= height[j]，
 * 那么i++，因为在这里height[i]是瓶颈，j往里移只会减少面积，不会再增加area。
 * 这是一个贪心的策略，每次取两边围栏最矮的一个推进，希望获取更多的水。
 *
 * 一个不严格的证明：
 * 当height[i] <= height[j]时，为什么是i++，而不是j++来获取可能更多的水？
 * 假设j' > j，之所以j'往左移，是因为存在height[i'] > height[j'] (i’ <= i), 
 * 而那时area' = (j' - i') * min(height[i'], height[j'])，
 * 因为height[j'] == min(height[i'], height[j'])，所以area' = (j' - i') * height[j']。
 * 而i 和 j'构成的面积area = (j' - i) * min(height[i], height[j'])。
 * area' >= area，所以j不需要往右移。
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if( size < 2 )
            return 0;
        
        int maxv = 0;
        int lp = 0;
        int rp = size-1;
        while( lp < rp ){
            int area = min( height[lp], height[rp] ) * (rp - lp);
            maxv = (area > maxv) ? area : maxv;
            if( height[lp] <= height[rp] )
                lp++;
            else
                rp--;
        }
        
        return maxv;
    }
};
