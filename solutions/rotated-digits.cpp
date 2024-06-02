class Solution {
public:
    int rotatedDigits(int n) 
    {
        map<int,int> m;
        m[0]=0; m[1]=1; m[8]=8; m[6]=9; m[9]=6; m[2]=5; m[5]=2;
        int count=0;
        for(int x=1; x<=n; x++)
        {
            string s=to_string(x);
            auto i1=s.find("2"), i2=s.find("5"), i3=s.find("6"), i4=s.find("9"), i5=s.find("3"), i6=s.find("4"), i7=s.find("7");
            if((i1!=string::npos || i2!=string::npos || i3!=string::npos || i4!=string::npos) && (i5==string::npos && i6==string::npos && i7==string::npos)) count++;
        }
        return count;
    }
};
