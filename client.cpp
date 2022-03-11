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
        std::cout<<"====================="<<std::endl;
        std::cout<<"DeviceID: "<<dev.first<<std::endl;
        printf("type:%d state:%d authTime:%d dhcpTime:%d ip:%s colonyID:%s \nswCapability:%d forwardCapability:%d linkNum:%d\n",
            dev.second.type,dev.second.state,dev.second.authTime,dev.second.dhcpTime,dev.second.ip.c_str(),
            dev.second.colonyID.c_str(),dev.second.swCapability,dev.second.forwardCapability,dev.second.linkNum);


        printf("ports:\n");
        for(int portID=0;portID<dev.second.peers.size();++portID){
            printf("port%d:\n",portID);
            for(int peerID=0;peerID<dev.second.peers[portID].size();++peerID){
                printf("\tpeer%d: ",peerID);
                std::cout<<dev.second.peers[portID][peerID]<<std::endl;
            }
        }

    }
    
    transport->close();
    return 0;
}
