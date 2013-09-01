/** Text Justification

Given an array of words and a length L, format the text such that each line has
exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words
as you can in each line. Pad extra spaces ' ' when necessary so that each line 
has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty 
slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted
between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you
do in this case?
In this case, that line should be left-justified.

*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> justified;
        
        if( L ==1 )
            return words;
        
        int curLineStart = 0;
        int curChars = 0;
        for( int curPos = 0; curPos < words.size(); curPos++ ){
            int slots = curPos - curLineStart;
            bool canHoldMore = ( curChars + slots + words[curPos].size() ) <= L;
            if( canHoldMore ){
                curChars += words[curPos].size();
                continue;
            }
            
            slots = curPos -1 - curLineStart;
            int spacesNum = L - curChars;            
            int spacesEachSlot = (slots >0)? (spacesNum / slots) : 0;
            int spacesMoreLeft = spacesNum - ( slots * spacesEachSlot );
            string curLine;
            for( int i = curLineStart; i < curPos; i++ ){
                curLine.append( words[i] );
                if( i != curPos-1 )
                    if( spacesMoreLeft > 0 )
                        curLine.append( getSpaces( spacesEachSlot + 1 ) );
                    else
                        curLine.append( getSpaces( spacesEachSlot ) );
                
                spacesMoreLeft--;
            }
            
            int moreSpaces = L - curLine.size();
            if( moreSpaces > 0 )
                curLine.append( getSpaces( moreSpaces ) );
            justified.push_back( curLine );
            
            // Switch to next new line
            curLineStart = curPos;
            curChars = words[curPos].size();
        }
        
        // handle the last line
        string curLine;
        curChars = 0;
        for( int i = curLineStart; i < words.size(); i++ ){
            if( i != words.size()-1 ){
                curChars += ( words[i].size() + 1 );
                curLine.append( words[i] + string(" ") );
            }
            else{
                curChars += words[i].size();
                curLine.append( words[i] );
            }
        }
        int spaces = L - curChars;
        if( spaces > 0 )
            curLine.append( getSpaces(spaces) );
        
        justified.push_back( curLine );
        
        return justified;
    }
    
    string getSpaces(int n){
        string s;
        for( int i = 0; i < n; i++ )
            s.push_back(' ');
        return s;
    }
};
