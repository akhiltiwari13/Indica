cmake_minimum_required(VERSION 3.10)
project(ADT_IMPLEMENTATION)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Trie)
add_subdirectory(Heap)

add_executable(BinarySearchTreeImpl BinarySearchTreeImpl.cpp)
add_executable(DoublyLinkedListImpl DoublyLinkedListImpl.cpp)
add_executable(LinkedListImpl LinkedListImpl.cpp)
add_executable(PriorityQueueLinkedListImpl PriorityQueueLinkedListImpl.cpp)
add_executable(QueueLinkedListImpl QueueLinkedListImpl.cpp)
add_executable(QueueArrayImpl QueueArrayImpl.cpp)
add_executable(StackLinkedListImpl StackLinkedListImpl.cpp)
add_executable(StackArrayImpl StackArrayImpl.cpp)
add_executable(BST BST.cpp)
add_executable(LinkedListNaiveImpl LinkedListNaiveImpl.cpp)

