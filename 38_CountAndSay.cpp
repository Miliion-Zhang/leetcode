/** Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        if( n < 1 )
            return string();
        string *ret = new string();
        string *str = new string();
        
        ret->push_back('1');
        while( n > 1 ){
            string *tmp = str;
            str = ret;
            ret = tmp;
            ret->clear();
            
            char last = str->at(0);
            int cnt = 1;
            for( int i = 1; i < str->size(); i++ ){
                if( str->at(i) == last )
                    cnt++;
                else{
                    ret->append( to_string(cnt) );
                    ret->push_back( last );
                    last = str->at(i);
                    cnt = 1;
                }
            }
            ret->append( to_string(cnt) );
            ret->push_back( last );
            
            n--;
        }
        
        return *ret;
    }
};
