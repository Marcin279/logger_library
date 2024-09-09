# Logger library

## Building environment

### Create Network for connection between logger_library and python server

1. Create network: </br>
   `docker network create log_network`

### Build logger_library_image
1. Build image: </br>
`docker build -t logger_library_env:1 .`

2. Opt - Run container: </br>
`docker run --name logger_library_container --mount type=bind,source="$(pwd)",target=/logger_library -it logger_library_env:1`

3. Run container with network option: </br>
`docker run --name logger_library_container --network log_network --mount type=bind,source="$(pwd)",target=/logger_library -it logger_library_env:1`

4. Running container: </br>
`docker start -i logger_library_container`

5. Stopping container: </br>
`docker stop logger_library_container`

6. Enter to running container: </br>
`docker exec -it <container_name/container_id> /bin/bash `


### Create python server
1. Build image with python server: </br>
`docker build -t log_server_image .`

2. Run container with network option for python server: </br>
`docker run -d --name log_server --network log_network -p 8090:8090 log_server_image`
