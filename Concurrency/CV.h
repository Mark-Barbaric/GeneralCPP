#pragma once
#include <queue>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <thread>

class ThreadedQueue{

    std::mutex mt;
    std::condition_variable cv;
    std::queue<int> q;
    bool ready{false};

public:

    void populateQueue(std::vector<int>& nums){
        std::cout << "Preparing data.\n";
        //1 acquire mutex
        std::lock_guard<std::mutex>lk(mt);
        std::cout << "Sleeping for 2 seconds.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        // 2. modify shared data
        for(const auto n : nums){
            q.push(n * 2);
        }
        ready = true;
        cv.notify_all();
    }

    void printQueue(){
        std::cout << "Attempting to process data.\n";
        std::unique_lock<std::mutex>lk(mt);
        cv.wait(lk, [this]{
            std::cout << "Waiting for condition variable.\n";
            return this->ready;});

        while(!q.empty()){
            std::cout << q.front() << ",";
            q.pop();
        }
        std::cout << std::endl;

        ready = false;
        lk.unlock();
        cv.notify_all();
    }

};