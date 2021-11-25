# thrift demo
## install thrift

ubuntu20.04上只能安装较新版本的 thrift，这里以 0.14.2 为例。0.9.2 只能在 ubuntu 16.04 上安装成功。

```
sudo apt-get install automake bison flex g++ git libboost-all-dev libevent-dev libssl-dev libtool make pkg-config
wget https://downloads.apache.org/thrift/0.14.2/thrift-0.14.2.tar.gz
tar -zxf thrift-0.14.2.tar.gz
cd thrift-0.14.2
./configure
sudo make
sudo make install
sudo ln -s /usr/local/lib/libthrift-0.14.2.so /usr/lib/
```
## build and run
```
make gen
make build-client
make build-server
./server
./client

```

