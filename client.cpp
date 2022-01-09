#include "ConServiceThrift/ConService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include<iostream>
#include<stdio.h>
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;



int main(int argc, char **argv) {
    std::shared_ptr<TSocket> socket(new TSocket("localhost", 2022)); //注意此处的ip和端口
    std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    transport->open();

    // 我们的代码写在这里
    ConServiceClient client(protocol);
    std::map<std::string, DeviceMSGThrift>  _return;
    client.getTopo(_return);
    for(auto dev:_return){
        std::cout<<dev.first<<std::endl;
        printf("%d\n",dev.second.type);
    }
    
    transport->close();
    return 0;
}
