gen:
	mkdir ConServiceThrift
	thrift -out ConServiceThrift --gen cpp ConService.thrift
	rm ConServiceThrift/*.skeleton.cpp

build-client:
	g++ ConServiceThrift/*.cpp ConServiceThrift/*.h client.cpp -o client -lthrift -Ithrift

build-server:
	g++ ConServiceThrift/*.cpp ConServiceThrift/*.h server.cpp -o server -lthrift -Ithrift

clean:
	rm -rf ConServiceThrift
	rm -f server client
