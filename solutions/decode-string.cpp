// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decode(string s)
    {
        // find first closing bracket
        int pos = s.find("]");
        if(pos==string::npos) 
            return s;
        
        // One part with multiplier and string
        
        // end index
        int end = pos+1;
        
        pos--;
        string toRepeat = "";
        
        // get string to repeat
        while(s[pos]!='[')
        {
            toRepeat = s[pos] + toRepeat;
            pos--;
        }
        pos--;
        
        // get the multiplier form a number
        int count = 0;
        int toMul = 1;
        while(pos >=0 && isdigit(s[pos]))
        {
            int digit = s[pos] - '0';
            count = digit*toMul + count; 
            toMul *= 10;
            pos--;
        }
        
        // start index
        int start = pos;
        
        // get repeated string
        string repeatedString = "";
        for(int cnt = 0; cnt<count;cnt++) 
            repeatedString += toRepeat;
        
        // insert it into correct position
        string generatedString = s.substr(0,start+1) + repeatedString + s.substr(end);
        
        // recursive call again
        return decode(generatedString);
    }
    
    string decodeString(string s) {
        
        return decode(s);
    }
};