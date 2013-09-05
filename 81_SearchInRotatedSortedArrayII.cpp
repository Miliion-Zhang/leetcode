/** Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    /**
     * Use binary search and time cost is O(logn) and need O(1) space. 
     * Note:
     *      (1) In worst case, should search both part by binary search, so the
     *          time cost is O(2*logn) = O(logn).
     *      (2) The only difference with question 33 is that if duplicates exist,
     *          then in some cases we can't tell which part is rotated and which
     *          not. 
     *          e.g., given [1,1,1,2,1,1,1,1,1,1,1], and target=2, then in first step,
     *          both parts seem like normal, so need search them both all recursively.
     */
    bool search(int A[], int n, int target) {
        bool ret = false;    //found or not
        if( n < 1 )
            return false;
        
        if( n==1 ){
            if( A[0] == target )
                return true;
            else
                return false;
        }
        
        int begin = 0;
        int end = n-1;
        while(1){
            if( end - begin + 1 <= 2 ){//end of search, only one or two elements left
                if( A[end] == target )
                    ret = true;
                else if( A[begin] == target )
                    ret = true;
                
                break;
            }
            
            int middle = begin + (end - begin) / 2;
            if( A[middle] == target ){//find target!
                ret = true;
                break;
            }
            else{
                bool leftRotated = isRotated(A, begin, middle);
                bool rightRotated = isRotated(A, middle, end);
                
                
                // firstly figure out if target located in normal area(not rotated),
                // if not, search in the other area.
                if( leftRotated ){//left half is rotated                    
                    if( target >= A[middle+1] && target <= A[end] )
                        begin = middle+1;   // Search right half of A
                    else
                        end = middle-1;     // Search left half of A
                }
                else if(rightRotated){
                    if( target >= A[begin] && target <= A[middle-1] )
                        end = middle-1;     // Search left half of A
                    else
                        begin = middle+1;   // Search right half of A
                }
                else{   //Can't tell which part is rotated, so must search in both sections
                    int len1 = middle - begin;
                    ret = search( A+begin, len1, target );
                    if( ret )
                        break;
                    
                    int len2 = end - middle;
                    ret = search( A+middle+1, len2, target );
                    break;
                }
            }            
        }
           
        return ret;
    }
    
    
    inline bool isRotated(int A[], int begin, int end){
        return A[begin] > A[end];
    }
};
