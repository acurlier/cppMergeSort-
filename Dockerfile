FROM ubuntu:20.04 as builder

WORKDIR /cpp
COPY . /cpp/

RUN apt-get update && apt-get install -yq \
        build-essential \ 
    && rm -rf /var/lib/apt/lists/*

RUN g++ -o app.out -Wall -O3 main.cpp Generator.cpp MergeSort.cpp

FROM ubuntu:20.04

WORKDIR /dist
COPY --from=builder /cpp/app.out .

CMD ./dist/app.out