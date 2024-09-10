# Use an official Ubuntu as a parent image
FROM ubuntu:latest

# Install essential tools and libraries
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    wget \
    unzip \
    libboost-all-dev \
    git \
    valgrind \
    vim \
    gdb \
    rsync \
    tar \
    libcurl4-openssl-dev \
    dos2unix

# Install the newest GCC compiler
RUN apt-get install -y software-properties-common && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y gcc-11 g++-11 && \
    update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 90 --slave /usr/bin/g++ g++ /usr/bin/g++-11

# Install Google Test framework
RUN mkdir /gtest && \
    cd /gtest && \
    wget https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip && \
    unzip release-1.11.0.zip && \
    cd googletest-release-1.11.0 && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install

# Set environment variable for Google Test
ENV GTEST_ROOT=/gtest/googletest-release-1.11.0

# Copy your C++ project files
COPY . /logger_library

# Convert scripts Windows to Unix format
RUN dos2unix /logger_library/run_exec.sh && \
    dos2unix /logger_library/clear.sh && \
    dos2unix /logger_library/run_test.sh

# Set the working directory
WORKDIR /logger_library

CMD ["tail", "-f", "/dev/null"]