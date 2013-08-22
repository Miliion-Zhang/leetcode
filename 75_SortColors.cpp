/** Sort Colors

    Given an array with n objects colored red, white or blue, sort them so that
    objects of the same color are adjacent, with the colors in the order red, 
    white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
    and blue respectively.

    Note:
    You are not suppose to use the library's sort function for this problem.

    Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
    array with total number of 0's, then 1's and followed by 2's.

    Could you come up with an one-pass algorithm using only constant space?
*/


class Solution {
public:
    /**
     * State A:  scan the array from left to right, 
     *  1) when find 0, write to leftwp position, and move on to next;
     *  2) when find 1, just move on to next;
     *  3) when find 2, jump to state B;
     *
     * State B: scan the array from right to left,
     *  1) when find 2, write to rightwp position, and move on to next;
     *  2) when find 1, just move on to next;
     *  3) when find 0, swap the values with indexs are leftwp and rightwp,
     *      jump to state A;
     *
     * State C: when done with A/B, try to fill the left space in array with 1
     */
    void sortColors(int A[], int n) {
        if( n < 2 ) // no need to sort
            return;
        
        int leftrp = 0;
        int leftwp = 0;
        int rightrp = n-1;
        int rightwp = n-1;
        
        bool readLeft = true;
        while( leftrp <= rightrp ){
            if( readLeft ){     // Read from left to right
                if( A[leftrp] == 2 ){
                    readLeft = !readLeft;
                    continue;
                }
                
                if( A[leftrp] == 0 ){
                    A[leftwp] = 0;
                    leftrp++;
                    leftwp++;
                }
                else
                    leftrp++;
            }
            else{               // Read from right to left
                if( A[rightrp] == 0 ){
                    A[leftwp] = 0;
                    leftrp++;
                    leftwp++;
                    A[rightwp] = 2;
                    rightrp--;
                    rightwp--;
                    
                    readLeft = !readLeft;
                    continue;
                }
                
                if( A[rightrp] == 2 ){
                    A[rightwp] = 2;
                    rightrp--;
                    rightwp--;
                }
                else
                    rightrp--;
            }
        }
        
        // Fill the left space in array with 1
        for( int i = leftwp; i <= rightwp; i++ )
            A[i] = 1;
        
    }
};
