# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(BlockchainPoW)

set(CMAKE_CXX_STANDARD 14)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the source files
add_executable(BlockchainPoW
    src/Block.cpp
    src/Blockchain.cpp
    src/BlockchainWithPoW.cpp
    src/main.cpp
)

# Link OpenSSL (optional for SHA-256 hashing)
find_package(OpenSSL REQUIRED)
target_link_libraries(BlockchainPoW OpenSSL::Crypto)
