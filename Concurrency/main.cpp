#include "CV.h"

struct ThreadGuard{

    std::vector<std::thread>& m_threads;

    explicit ThreadGuard(std::vector<std::thread>& threads):m_threads(threads){

    }

    ~ThreadGuard() {
        for(auto& t : m_threads){
            if(t.joinable()){
                t.join();
            }
        }
    }
};


int main(int argc, char* argv[]){

    std::vector<int> nums {1,2,3,4,5};
    std::vector<std::thread> threads;
    ThreadedQueue q;
    std::thread thread1(&ThreadedQueue::populateQueue, &q, std::ref(nums));
    std::thread thread2(&ThreadedQueue::printQueue, &q);
    threads.push_back(std::move(thread1));
    threads.push_back(std::move(thread2));
    ThreadGuard threadGuard(threads);
    return 0;
}