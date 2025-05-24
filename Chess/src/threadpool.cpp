#include "threadpool.h"

ThreadPool::ThreadPool(unsigned int threadCount) {
    for (unsigned int i = 0; i < threadCount; ++i) {
        m_workers.emplace_back([this] { runWorker(); });
    }
}

ThreadPool::~ThreadPool() {
    shutdown();
}

void ThreadPool::submit(std::function<void()> job) {
    {
        std::unique_lock<std::mutex> lock(m_jobsMutex);
        m_jobs.emplace_back(std::move(job));
    }
    m_jobsCv.notify_one();
}

void ThreadPool::runWorker() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(m_jobsMutex);
            m_jobsCv.wait(lock, [this]{
                return m_stopping.load() || !m_jobs.empty();
            });
            if (m_stopping.load() && m_jobs.empty())
                return;
            task = std::move(m_jobs.front());
            m_jobs.pop_front();
        }
        task();
    }
}

void ThreadPool::shutdown() {
    m_stopping.store(true);
    m_jobsCv.notify_all();
    for (auto &w : m_workers) {
        if (w.joinable()) w.join();
    }
    m_workers.clear();
}
