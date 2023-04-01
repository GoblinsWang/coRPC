#ifndef CORPC_NET_FD_EVNET_H
#define CORPC_NET_FD_EVNET_H

#include <functional>
#include <memory>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <assert.h>
#include <mutex>
#include "net_socket.h"
#include "../log/logger.h"
#include "../coroutine/coroutine.h"
#include "../coroutine/rw_mutex.h"

namespace corpc
{

    class Processor;

    enum IOEvent
    {
        READ = EPOLLIN,
        WRITE = EPOLLOUT,
        ETModel = EPOLLET,
    };

    class FdEvent : public std::enable_shared_from_this<FdEvent>
    {
    public:
        using ptr = std::shared_ptr<FdEvent>;

        explicit FdEvent(int fd);

        virtual ~FdEvent();

        void setSocket(NetSocket::ptr Sock);

        int getFd() const;

        void setProcessor(Processor *r);

        void setCoroutine(Coroutine *cor);

        Coroutine *getCoroutine();

        void clearCoroutine();

    public:
        std::mutex m_mutex;

    protected:
        int m_fd{-1};

        NetSocket::ptr m_socket = nullptr;

        Coroutine *m_coroutine{nullptr};
    };

    class FdEventContainer
    {

    public:
        FdEventContainer(int size);

        FdEvent::ptr getFdEvent(int fd);

    public:
        static FdEventContainer *GetFdContainer();

    private:
        RWMutex m_rwmutex;
        std::vector<FdEvent::ptr> m_fds;
    };

}

#endif
