class Solution {
public:
    int maxDiff(int num) {
        string st = to_string(num);

        int sz = st.size();

        int i = 0;
        char mn_dgt = '.', mch = '0';
        string t = st;
        while(i < sz and (t[i] == '1' or t[i] == '0')) i++; 
        while(i < sz) {
            if(t[i] != '0') {
                if(mn_dgt == '.') {
                    if(!(t[i] == '1' and t[0] == '1')) {
                        if(i == 0) {
                            mch = '1';
                        }
                        mn_dgt = t[i]; 
                        t[i] = mch;
                    }
                } else if(t[i] == mn_dgt) {
                    t[i] = mch;
                }
            }
            i++;
        }

        int mn_num = stoi(t);
        // cout << mn_num << endl;

        i = 0;
        char mx_dgt = '.';
        t = st;
        while(i < sz) {
            if(t[i] != '9') {
                if(mx_dgt == '.') {
                    mx_dgt = t[i]; 
                    t[i] = '9';
                } else if(t[i] == mx_dgt) {
                    t[i] = '9';
                }
            }
            i++;
        }

        int mx_num = stoi(t);

        return mx_num - mn_num;
    }
};
