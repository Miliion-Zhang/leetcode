/** Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, 
otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    /**
     * Use binary search and time cost is O(logn) and need O(1) space. 
     * Note:
     *      (1) This is a non-recursive version, so it may be a little faster.
     *      (2) The only difference with normal binary search is when the
     *         middle one is not the target, should determine which part
     *         is not rotated ; if the target is in that range, continue to
     *         search in that part, otherwise search in the rotated part.
     */
    int search(int A[], int n, int target) {
        int tp = -1;    //target index
        if( n < 1 )
            return -1;
        
        if( n==1 ){
            if( A[0] == target )
                return 0;
            else
                return -1;
        }
        
        int begin = 0;   // begin index of the valid section
        int end = n-1;  // end index, including this one
        while(1){
            if( end - begin + 1 <= 2 ){//end of search, only one or two elements left
                if( A[end] == target )
                    tp = end;
                else if( A[begin] == target )
                    tp = begin;
                
                break;
            }
            
            int middle = begin + (end - begin) / 2;
            if( A[middle] == target ){//find target!
                tp = middle;
                break;
            }
            else{
                bool leftRotated = isRotated(A, begin, middle);
                
                // firstly figure out if target located in normal area(not rotated),
                // if not, search in the other area.
                if( leftRotated ){//left half is rotated                    
                    if( target >= A[middle+1] && target <= A[end] )
                        begin = middle+1;   // Search right half of A
                    else
                        end = middle-1;     // Search left half of A
                }
                else{
                    if( target >= A[begin] && target <= A[middle-1] )
                        end = middle-1;     // Search left half of A
                    else
                        begin = middle+1;   // Search right half of A
                }                
            }            
        }
           
        return tp;
    }
    
    
    inline bool isRotated(int A[], int begin, int end){
        return A[begin] > A[end];
    }
};
