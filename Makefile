TARGET = test_app 
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
CC = g++
CLANG = clang++
INCLUDES = 
LIBS = 
CCFLAGS = -std=c++11
LINKFLAGS = 

all:$(TARGET)
$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(INCLUDES) $(LIBS) $(LINKFLAGS)
$(OBJS): $(SRCS)
	$(CC) -c $^ $(CCFLAGS)

clean:
	rm $(TARGET)
	rm $(OBJS)

.PHONY:all

