# Logger library

## Building environment

1. Build image: </br>
`docker build -t logger_library_env:1 .`

2. Run container: </br>
`docker run --name logger_library_container --mount type=bind,source="$(pwd)",target=/logger_library -it logger_library_env:1`

3. Running container: </br>
`docker start -i logger_library_container`

4. Stopping container: </br>
`docker stop logger_library_container`

5. Enter to running container: </br>
`docker exec -it <container_name/container_id> /bin/bash `