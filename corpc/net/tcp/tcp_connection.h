// #ifndef CORPC_NET_TCP_TCP_CONNECTION_H
// #define CORPC_NET_TCP_TCP_CONNECTION_H

// #include <memory>
// #include <vector>
// #include <queue>
// // #include "corpc/comm/log.h"
// // #include "corpc/net/fd_event.h"
// // #include "corpc/net/reactor.h"
// // #include "corpc/net/tcp/tcp_buffer.h"
// // #include "corpc/coroutine/coroutine.h"
// // #include "corpc/net/http/http_request.h"
// // #include "corpc/net/tinypb/tinypb_codec.h"
// // #include "corpc/net/tcp/io_thread.h"
// // #include "corpc/net/tcp/tcp_connection_time_wheel.h"
// // #include "corpc/net/tcp/abstract_slot.h"
// // #include "corpc/net/net_address.h"
// // #include "corpc/net/mutex.h"
// #include "../common.h"
// #include "../net/fd_event.h"
// #include "tcp_buffer.h"
// #include "../address.h"

// namespace corpc
// {

//     class TcpServer;
//     class TcpClient;
//     class IOThread;

//     enum TcpConnectionState
//     {
//         NotConnected = 1, // can do io
//         Connected = 2,    // can do io
//         HalfClosing = 3,  // server call shutdown, write half close. can read,but can't write
//         Closed = 4,       // can't do io
//     };

//     class TcpConnection : public std::enable_shared_from_this<TcpConnection>
//     {

//     public:
//         using ptr = std::shared_ptr<TcpConnection>;

//         TcpConnection(corpc::TcpServer *tcp_svr, corpc::IOThread *io_thread, int fd, int buff_size, NetAddress::ptr peer_addr);

//         // TcpConnection(corpc::TcpClient *tcp_cli, corpc::Reactor *reactor, int fd, int buff_size, NetAddress::ptr peer_addr);

//         void setUpClient();

//         void setUpServer();

//         ~TcpConnection();

//         void initBuffer(int size);

//         enum ConnectionType
//         {
//             ServerConnection = 1, // owned by tcp_server
//             ClientConnection = 2, // owned by tcp_client
//         };

//     public:
//         void shutdownConnection();

//         TcpConnectionState getState();

//         void setState(const TcpConnectionState &state);

//         TcpBuffer *getInBuffer();

//         TcpBuffer *getOutBuffer();

//         AbstractCodeC::ptr getCodec() const;

//         bool getResPackageData(const std::string &msg_req, TinyPbStruct::pb_ptr &pb_struct);

//         void registerToTimeWheel();

//         Coroutine::ptr getCoroutine();

//     public:
//         void MainServerLoopCorFunc();

//         void input();

//         void execute();

//         void output();

//         void setOverTimeFlag(bool value);

//         bool getOverTimerFlag();

//         void initServer();

//     private:
//         void clearClient();

//     private:
//         TcpServer *m_tcp_svr{nullptr};
//         TcpClient *m_tcp_cli{nullptr};
//         IOThread *m_io_thread{nullptr};
//         Reactor *m_reactor{nullptr};

//         int m_fd{-1};
//         TcpConnectionState m_state{TcpConnectionState::Connected};
//         ConnectionType m_connection_type{ServerConnection};

//         NetAddress::ptr m_peer_addr;

//         TcpBuffer::ptr m_read_buffer;
//         TcpBuffer::ptr m_write_buffer;

//         Coroutine::ptr m_loop_cor;

//         AbstractCodeC::ptr m_codec;

//         FdEvent::ptr m_fd_event;

//         bool m_stop{false};

//         bool m_is_over_time{false};

//         std::map<std::string, std::shared_ptr<TinyPbStruct>> m_reply_datas;

//         std::weak_ptr<AbstractSlot<TcpConnection>> m_weak_slot;

//         RWMutex m_mutex;
//     };

// }

// #endif
