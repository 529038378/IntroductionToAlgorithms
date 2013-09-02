CXX =  g++
CPPFLAGS = -Wall
obj = ArrayStack.o ListStack.o DataIO.o Display.o ia.o

ia:$(obj)
	$(CXX) -o ia $(obj)

all:$(obj)
$(obj): %.o:%.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@




.PHONY: clean
clean:
	rm -f $(obj)
	rm -rf ia
