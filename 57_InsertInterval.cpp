/** Insert Interval

Given a set of non-overlapping intervals, insert a new interval into the 
intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their
start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as 
[1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
 * This edition use the same way of question 56.
 * We can simply add the newInterval to intervals, and then call the function in
 * question 56 and everything will be done.
 *
 * But in this way, should sort the items in intervals. Because the intervals in
 * this question is already sorted, what we need do is insert the new one to it.
 *
 * Meanwhile, if we directly insert the new one to the right position of intervals,
 * it will still cost more useless time because insert a new element to the middle
 * of a vector will cause shifting all elements after it.
 * 
 * So, I choose to use merge sort by my own hand, see the code below.
 * Note:
 *   (1)
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        
        if( intervals.size() < 1 ){
            ret.push_back( newInterval );
            return ret;
        }
        
        bool hasUsed = false;   // if the new one has been used
        int srcIndex = 0;       // current read index in intervals
        
        ret.push_back( getMinStartInterval(intervals, srcIndex, newInterval, hasUsed) );
        int lastRet = 0;        
        while(1){
            if( hasUsed && srcIndex >= intervals.size() )
                break;
            
            Interval intv = getMinStartInterval(intervals, srcIndex, newInterval, hasUsed);            
            
            if( intv.start > ret[lastRet].end ){// not overlap
                ret.push_back( intv );
                lastRet++;
            }
            else{   // Do overlap, combine them together
                ret[lastRet].end = max(intv.end, ret[lastRet].end);
            }
        }
        
        return ret;
    }
    
    /**
     * Much more like merge sort, try to get the min one from intervals or
     * the new one.
     */
    inline Interval getMinStartInterval(vector<Interval> &intervals, 
                                        int &srcIndex,
                                        Interval &newOne, 
                                        bool &hasUsed){
        
        if( srcIndex >= intervals.size() ){
            hasUsed = true;
            return newOne;
        }
        
        Interval ret;
        if( hasUsed ){
            ret = intervals[srcIndex];
            srcIndex++;
        }        
        else if( intervals[srcIndex].start < newOne.start ){
            ret = intervals[srcIndex];
            srcIndex++;
        }
        else{
            hasUsed = true;
            ret = newOne;
        }
        
        return ret;
    }
};



 /**
  * First edition.
  * It's a little complicated.
  */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> merged;
        if( intervals.size() < 1 ){
            merged.push_back( newInterval );
            return merged;
        }
        
        
        // new one stand alone in left or in the last
        if( newInterval.end < intervals[0].start ){
            merged.push_back( newInterval );
            appendToIntervals(intervals, merged);
            return merged;
        }
        else if( newInterval.start > intervals[ intervals.size()-1 ].end ){
            appendToIntervals(intervals, merged);
            merged.push_back( newInterval );
            return merged;
        }
        
        int mergeStart = 0;
        int mergeEnd = 0;
                   
        bool found = false;
        Interval sInterval = newInterval;
        for( int i = 0; i < intervals.size(); i++ ){
            
            
            if( intervals[i].end < newInterval.start ){ // no overlap
                Interval intv = Interval( intervals[i].start, intervals[i].end );
                merged.push_back( intv );
            }
            else if( intervals[i].start > newInterval.end  ){
                mergeStart = i-1;
                sInterval = newInterval;
                break;
            }
            else{   // do have overlap, stop here
                mergeStart = i;
                sInterval = intervals[i];
                break;
            }
        }   
                
         
        sInterval.start = ( sInterval.start < newInterval.start ) ? sInterval.start : newInterval.start;
        
        if( sInterval.end >= newInterval.end ){ // only need merge current with the new one
            mergeEnd = mergeStart;
            sInterval.end = sInterval.end;
        }
        else if( newInterval.end >= intervals[ intervals.size()-1 ].end ){
            mergeEnd = intervals.size();
            sInterval.end = newInterval.end;
        }
        else {
            for( int i = mergeStart; i < intervals.size(); i++ ){
                mergeEnd = i;
                if( newInterval.end >= intervals[i].start
                  &&newInterval.end <= intervals[i].end ){
                    mergeEnd = i;
                    break;
                }
                
                if( newInterval.end < intervals[i].start){
                    mergeEnd = i-1;
                    break;
                }
            }
            
            sInterval.end = max(intervals[mergeEnd].end, newInterval.end);
            
        }
        
        merged.push_back( sInterval );
        
        // append the left
        for( int i = mergeEnd+1; i < intervals.size(); i++ )
            merged.push_back( Interval( intervals[i].start, intervals[i].end ) );
        
        
        return merged;        
    }
    
    void appendToIntervals(const vector<Interval> &src, vector<Interval> &dst){
        for( int i = 0; i < src.size(); i++ )
            dst.push_back( src[i] );
    }
};
