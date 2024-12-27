#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <pthread.h>
#include <queue>

class MsgQueue
{
  public:
    MsgQueue()
    {
    }

    ~MsgQueue()
    {
    }

    void push(int v)
    {
        {
            std::lock_guard<std::mutex> guard(_mutex);
            _queue.push(v);
        }
        _cond.notify_all();
    }

    bool pop(int &v)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        while (_queue.empty())
        {
            _cond.wait(lock);
        }

        v = _queue.front();
        _queue.pop();
        return true;
    }

    std::queue<int> _queue;
    std::mutex _mutex;
    std::condition_variable _cond;
};

void *consume(void *param)
{
    MsgQueue *msgQueue = static_cast<MsgQueue *>(param);
    while (true)
    {
        int v = 0;
        msgQueue->pop(v);
        std::cout << v << "\n";
    }
}

int main(int argc, char *argv[])
{
    MsgQueue msgQueue;
    pthread_t pid;

    pthread_create(&pid, 0, consume, (void *)&msgQueue);
    int v = 0;
    while ((v = getchar()) != 'q')
    {
        msgQueue.push(v);
    }

    std::cout << "out \n";

    return 0;
}
