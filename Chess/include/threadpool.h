#pragma once

#include <vector>
#include <thread>
#include <deque>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadPool {
public:
    explicit ThreadPool(unsigned int threadCount);
    ~ThreadPool();

    void submit(std::function<void()> job);

    void shutdown();

private:
    void runWorker();

    std::vector<std::thread>        m_workers;
    std::deque<std::function<void()>> m_jobs;
    std::mutex                       m_jobsMutex;
    std::condition_variable          m_jobsCv;
    std::atomic<bool>                m_stopping{false};
};
