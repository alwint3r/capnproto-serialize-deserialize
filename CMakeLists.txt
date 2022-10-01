cmake_minimum_required(VERSION 3.10)

find_package(CapnProto)
capnp_generate_cpp(CAPNP_SRCS CAPNP_HDRS person.capnp)

project(SerializeDeserialize)

add_library(PersonLib ${CAPNP_SRCS})

add_executable(SerializePerson serialize.cpp)
target_link_libraries(SerializePerson PersonLib CapnProto::capnp)
target_include_directories(SerializePerson PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

add_executable(DeserializePerson deserialize.cpp)
target_link_libraries(DeserializePerson PersonLib CapnProto::capnp)
target_include_directories(DeserializePerson PRIVATE ${CMAKE_CURRENT_BINARY_DIR})