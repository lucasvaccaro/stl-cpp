all: MyDomain
MyDomain: main.o Node.o Array.o LinkedList.o Hash.o Map.o MultiMap.o Set.o MultiSet.o
	g++  main.o Node.o Array.o LinkedList.o Hash.o Map.o MultiMap.o Set.o MultiSet.o -o adt
main.o: main.cpp
	g++ -c main.cpp
Node.o: Node.cpp
	g++ -c Node.cpp
Array.o: Array.cpp
	g++ -c Array.cpp
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
Hash.o: Hash.cpp
	g++ -c Hash.cpp
Map.o: Map.cpp
	g++ -c Map.cpp
MultiMap.o: MultiMap.cpp
	g++ -c MultiMap.cpp
Set.o: Set.cpp
	g++ -c Set.cpp
MultiSet.o: MultiSet.cpp
	g++ -c MultiSet.cpp
clean:
	rm *.o adt
