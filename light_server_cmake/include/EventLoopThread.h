#ifndef _EVENTLOOPTHREAD_H_
#define _EVENTLOOPTHREAD_H_

#include "utils/Condition.h"
#include "utils/Mutex.h"
#include "utils/notCopyable.h"
#include "utils/Thread.h"

class EventLoop;

// one event loop per thread
// start an IO thread then waiting for events coming
class EventLoopThread : public notCopyable
{
public:
  typedef std::function<void(EventLoop *)> ThreadInitCallback;
  EventLoopThread(const ThreadInitCallback &cb = ThreadInitCallback());
  ~EventLoopThread();
  EventLoop *startLoop();

private:
  void threadFunc();

  bool existing_;

  EventLoop *loop_;
  ThreadInitCallback callback_;

  MutexLock mutex_;

  Condition cond_;

  Thread thread_;
};

#endif
