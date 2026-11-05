class DiningPhilosophers {
private:
    mutex forks[5];
public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int f1 = philosopher;
        int f2 = (philosopher + 1) % 5;
        
        // always lock the smaller index first
        if (f1 > f2) swap(f1, f2);

        unique_lock<mutex> lk1(forks[f1]);
        unique_lock<mutex> lk2(forks[f2]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};
