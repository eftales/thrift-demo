all:build-client build-server


gen:
	thrift --gen cpp student.thrift
	rm gen-cpp/Serv_server.skeleton.cpp

build-client:
	g++ gen-cpp/*.cpp gen-cpp/*.h client.cpp -o client -lthrift -Ithrift

build-server:
	g++ gen-cpp/*.cpp gen-cpp/*.h server.cpp -o server -lthrift -Ithrift

clean:
	rm -rf gen-cpp
	rm -f server client
