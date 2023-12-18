/*
 * FileName:     producer_consumer
 * Author: 8ucchiman
 * CreatedDate:  2023-03-24 13:48:32 +0900
 * LastModified: 2023-03-24 14:58:01 +0900
 * Reference: 8ucchiman.jp
 */

#include <iostream>
#include <condition_variable>
#include <deque>
#include <functional>
#include <mutex>
#include <thread>


class worker {
public:
    worker(): thread_([this]() {proc_worker(); }) {}
    ~worker() {
        wait_until_idle();
        request_termination();
        if (thread_.joinable()) {
            thread_.join();
        }
    }
    template<typename F>
    void run(F&& func) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (is_requested_termination) { return; }
        queue_.emplace_back(func);
        cond_.notify_all();
    }

    void wait_until_idle() {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_.wait(lock, [this]() { return queue_.empty() || is_requested_termination; });
    }

    void request_termination() {
        std::unique_lock<std::mutex> lock(mutex_);
        is_requested_termination = true;
        cond_.notify_all();
    }

private:
    void proc_worker() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock lock(mutex_);
                cond_.wait(lock, [this]() {return !queue_.empty() || is_requested_termination;});
                if (is_requested_termination) break;
                task = queue_.front();
                queue_.pop_front();
                cond_.notify_all();
            }
            task();
        }
    }
    bool is_requested_termination{ false };
    std::thread thread_;
    std::deque<std::function<void()>> queue_;
    std::mutex mutex_;
    std::condition_variable cond_;
};

//int main(void){
//    
//    return 0;
//}
