class H2O {
public:
    mutex m;
    condition_variable cv;
    int remH, remO;
    H2O() {
        remH = 2;
        remO = 1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{ return remH > 0;});
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        remH--;
        if(remH == 0 and remO == 0) {
            remH = 2;
            remO = 1;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return remO > 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        remO--;
        if(remH == 0 and remO == 0) {
            remH = 2;
            remO = 1;
        }
        cv.notify_all();
    }
};
