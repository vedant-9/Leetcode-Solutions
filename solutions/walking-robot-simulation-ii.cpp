// https://leetcode.com/problems/walking-robot-simulation-ii

class Robot {
public:
    int x=0,y=0,d=0,n,m; 
    string dir[4]={"East","North","West","South"};
    Robot(int width, int height) {
        n=width; m=height;
    }
    
    void move(int num) {
        // x y d
        if(num>=(2*n+2*m-4)) {
            num%=(2*n+2*m-4);
            if(x==0 and y==0 and d==0) d=3;
        }
        if(num==0) return;
        while(num) {
            if(d==0) {
                if(x+num<n) x+=num,num=0;
                else num-=(n-x-1),x=n-1,d=1;
            } else if(d==1) {
                if(y+num<m) y+=num,num=0;
                else num-=(m-y-1),y=m-1,d=2;
            } else if(d==2) {
                if(x-num>=0) x-=num,num=0;
                else num-=(x),x=0,d=3;
            } else {
                if(y-num>=0) y-=num,num=0;
                else num-=(y),y=0,d=0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir[d];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */