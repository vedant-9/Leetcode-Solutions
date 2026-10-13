import java.util.concurrent.Semaphore;

class FooBar {
    private int n;
    private final Semaphore fooTurn = new Semaphore(1);   // foo goes first, so it starts with a permit
    private final Semaphore barTurn = new Semaphore(0);   // bar must wait

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            fooTurn.acquire();
            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            barTurn.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            barTurn.acquire();
            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            fooTurn.release();
        }
    }
}
