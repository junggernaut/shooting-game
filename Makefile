CC=g++
CFLAGS=--std=c++14 
TARGET=final

$(TARGET):
	$(CC) $(CFLAGS) -o $@ final_skeleton_mac.cpp Screen_manager.cpp -lncurses


clean:
	rm -f *.o
	rm -f $(TARGET)
