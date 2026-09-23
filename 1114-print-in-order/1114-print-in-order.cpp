class Foo {
private:
    std::atomic<int> stage;

public:
    Foo() : stage(1) {}

    void first(std::function<void()> printFirst) {
        printFirst();
        stage.store(2, std::memory_order_release);
    }

    void second(std::function<void()> printSecond) {
        while (stage.load(std::memory_order_acquire) != 2) {}
        printSecond();
        stage.store(3, std::memory_order_release);
    }

    void third(std::function<void()> printThird) {
        while (stage.load(std::memory_order_acquire) != 3) {}
        printThird();
    }
};
