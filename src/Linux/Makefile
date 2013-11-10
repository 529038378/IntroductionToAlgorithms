CXX =  g++
CPPFLAGS = -Wall
obj = ArrayStack.o ListStack.o ArrayQueue.o CycleDoublyLinkList.o DataIO.o Display.o ia.o \
	BinarySearchTree.o RedBlackTree.o MergeFindSet.o HashTable.o SortAlgorithms.o

ia:$(obj)
	$(CXX) -o ia $(obj)

all:$(obj)
$(obj): %.o:%.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@




.PHONY: clean
clean:
	rm -f $(obj)
	rm -rf ia
