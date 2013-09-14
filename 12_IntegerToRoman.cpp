/** Integer to Roman

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    /**
     * For digitals in decade place or hundreds place or thousands place follow
     * the same rule to represent them in Roman.
     * Just need handle different sections with different procedure, which is 
     * [1,3], 4, 5, [6-8], 9 .
     */
    string intToRoman(int num) {
        char units[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string roman;
        int scale = 1000;
        int posUnits = 6;
        while( scale >= 1 ){
            int digital = num / scale;
            if( digital <= 3 ){
                roman.append(digital, units[posUnits]);
            }
            else if( digital == 4 ){
                roman.append(1, units[posUnits]);
                roman.append(1, units[posUnits+1]);
            }
            else if( digital == 5 ){
                roman.append(1, units[posUnits+1]);
            }
            else if( digital <= 8 ){
                roman.append(1, units[posUnits+1]);
                roman.append(digital-5, units[posUnits]);
            }
            else{
                roman.append(1, units[posUnits]);
                roman.append(1, units[posUnits+2]);
            }
            
            
            posUnits -= 2;
            num %= scale;
            scale /= 10;
        }
        
        return roman;
    }
};
