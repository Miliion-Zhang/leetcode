/** Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Note: the input intervals are in random order.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


/**
 * Sorting function for Intervals by `start` in ascending order.
 */
bool sortByStart( const Interval &v1, const Interval &v2){
    return v1.start < v2.start;
}    
    
class Solution {
public:
    /**
     * Firstly, sort the given intervals by `start` in ascending
     * order; then copy the first one to ret vector, and secondly,
     * try to merge the next one with the last one in ret, if do
     * overlap, them merge them; otherwise insert to ret and move
     * on to next.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if( intervals.size() < 1 )
            return ret;
        
        // sort intervals by `start` in ascending order
        sort(intervals.begin(),intervals.end(),sortByStart);
        
        ret.push_back( intervals[0] );
        int lastRet = 0;
        for( int i = 1; i < intervals.size(); i++ ){
            if( intervals[i].start > ret[lastRet].end ){// not overlap
                ret.push_back( intervals[i] );
                lastRet++;
            }
            else{   // Do overlap, combine them together
                ret[lastRet].end = max(intervals[i].end, ret[lastRet].end);
            }
        }
        
        return ret;
    }
    
    
};
