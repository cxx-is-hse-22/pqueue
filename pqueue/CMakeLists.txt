cmake_minimum_required(VERSION 3.10.0)
add_executable(pqueue-test pqueue.cpp pqueue_test.cpp)
target_link_libraries(pqueue-test PUBLIC doctest default)
add_test(NAME pqueue-test COMMAND pqueue-test --force-colors -d)
add_custom_target(cloud-test COMMAND pqueue-test --force-colors -d)
