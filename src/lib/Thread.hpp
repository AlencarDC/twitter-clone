#ifndef __Thread_hpp__
#define __Thread_hpp__

#include <thread>

class Thread {
  private: 
    std::thread* m_thread;

  public:
    Thread();
    virtual ~Thread();

    bool start();
    bool join();
    long unsigned int getId();
    static void* runThread(Thread* instance);
  
  private:
    virtual void* run() = 0;
};

#endif // __Thread_hpp__