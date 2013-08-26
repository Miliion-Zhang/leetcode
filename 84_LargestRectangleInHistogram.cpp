/**

Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle in the histogram.

@see : http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

@see : http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    /**
     * This can be solved by enumerating all possible left boarder and right
     * boder of an area which will cost O(n*n) time. But it won't pass the big
     * test set.
     *
     * I google it and learn the solution from 
     * @see: http://fisherlei.blogspot.com/2012/12/leetcode-largest-rectangle-in-histogram.html
     * Generally, it uses extra space to keep the continuous ascending sequences
     * of the given height.  I list the procedure here and will explain it later on.
     *
     *1) If current height is bigger than or equal to stack.top, then push it in;
     *2) If current height is smaller than stack.top, then pop the stack until
     *   stack.top < current height, meanwhile calculate the area fused by
     *   the popped items each time. At the last, fuse current height with all
     *   items as a new histogram bar with width > 1, and push it to stack.
     *3) At the end, pop out all items in stack and update max area if possible.
     *
     * The basic idea of this solution is that when current height is smaller than
     * the last one in ascending sequences, then it will be a barrier for the items
     * before it to expand more( they can expand to right but the min height is
     * limited by current height by now). So just pop the items out that bigger
     * than current height in stack, and try to fuse them as one big new histogram
     * bar with width > 1, meanwhile calculate the area of popped items can
     * combined together.
     *
     * The time cost is O(n)
     */
    int largestRectangleArea(vector<int> &height) {
        
        stack<int> hstack;
        stack<int> wstack;
        hstack.push(0); // the ascending sequences of height
        wstack.push(0); // the width of itmes in hstack
        int area = 0;
        
        for( int i = 0; i < height.size(); i++ ){
            if( height[i] >= hstack.top() ){ 
                hstack.push( height[i] );
                wstack.push( 1 );
            }
            else {
                int minH = INT_MAX;
                int width = 0;
                while( hstack.top() > height[i] ){
                    minH = min( minH, hstack.top() );
                    width += wstack.top();
                    hstack.pop();
                    wstack.pop();
                    area = max( area, minH * width );
                }
                
                hstack.push( height[i] );
                wstack.push( width + 1 );
            }
        }
        
        // pop all out
        int minH = INT_MAX;
        int width = 0;
        while( !hstack.empty() ){
            minH = min( minH, hstack.top() );
            width += wstack.top();
            hstack.pop();
            wstack.pop();
            area = max( area, minH * width );
        }
        
        return area;
    }
};
