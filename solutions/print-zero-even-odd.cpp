class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool canZeroPrint;
    int counter; 
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->canZeroPrint = true;
        this->counter = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        int cnt = n;
        while(cnt--) {
            cv.wait(lock, [this]{ return canZeroPrint; });
            printNumber(0);
            canZeroPrint = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while(counter <= n) {
            cv.wait(lock, [this]{ return counter > n or !canZeroPrint and counter % 2 == 0; });
            if(counter > n) return;
            printNumber(counter);
            counter++;
            canZeroPrint = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while(counter <= n) {
            cv.wait(lock, [this]{ return counter > n or !canZeroPrint and counter % 2 != 0; });
            if(counter > n) return;
            printNumber(counter);
            counter++;
            canZeroPrint = true;
            cv.notify_all();
        }
    }
};
