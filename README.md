# thrift demo
## install thrift
### ubuntu 20.04
ubuntu 20.04 可以通过 apt 直接安装

```
sudo apt install libthrift-dev thrift-compiler -y
```


### ubuntu 16.04
ubuntu 16.04 需要自行下载源码编译安装

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

