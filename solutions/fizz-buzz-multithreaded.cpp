class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);
        while(i <= n) {
            cv.wait(lock, [this]{ return i > n or (i % 3 == 0 and i % 5 != 0); });
            if(i > n) return;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);
        while(i <= n) {
            cv.wait(lock, [this]{ return i > n or (i % 3 != 0 and i % 5 == 0); });
            if(i > n) return;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);
        while(i <= n) {
            cv.wait(lock, [this]{ return i > n or (i % 3 == 0 and i % 5 == 0); });
            if(i > n) return;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while(i <= n) {
            cv.wait(lock, [this]{ return i > n or (i % 3 != 0 and i % 5 != 0); });
            if(i > n) return;
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};
