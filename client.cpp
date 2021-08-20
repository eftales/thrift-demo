#include "gen-cpp/Serv.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using boost::shared_ptr;

int main(int argc, char **argv) {
    boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090)); //注意此处的ip和端口
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    transport->open();

    // 我们的代码写在这里
    Student s;
    s.sno = 123;
    s.sname = "xiaoshe";
    s.ssex = 1;
    s.sage = 30;   
    ServClient client(protocol);
    client.put(s);
    
    transport->close();
    return 0;
}
