/** Simplify Path

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        vector<string> folders;
        
        string folder;
        /**
         * Will push new sub folder to vector, and pop one if find "../", or just
         * ignore it if find "./"
         */
        for( int i = 0; i <= path.size(); i++ ){
            if( path[i] == '/' || i == path.size() ){
                if( folder.compare( ".." ) == 0 ){
                    if( folders.size() )
                        folders.pop_back();
                }
                else if( folder.compare( "." ) == 0 ){
                    //should do nothing
                }
                else if( !folder.empty() ){
                    folders.push_back( folder );
                }
                
                // clear folder to get next sub folder
                folder.clear();
            }
            else{
                folder.push_back( path[i] );
            }
        }
        
        // get all sub folders and put them together
        for( int i = 0; i < folders.size(); i++ ){
            ret.push_back( '/' );
            ret.append( folders[i] );
        }
        
        if( ret.empty() )
            ret.push_back( '/' );
        
        return ret;
    }
};
