Hello World example for ROS Indigo.

# Compile it manually (without creating a package)

```
$ g++ src/hello_world/src/hello_world.cpp -o hello_world.out -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole
```

# Compile it with catkin tools
```
$ catkin build
```

# Step by Step Tutorial
```
### without any tool
mkdir ~/hello_world
cd ~/hello_world
touch hello_world.cpp
# edit the file with example code
g++ hello_world.cpp -o hello_world.out -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole

# run it with
./hello_world.out
```

```
### with build tool
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_create_pkg hello_world roscpp
cp ~/hello_world/hello_world.cpp ~/catkin_ws/src/hello_world/src/
# edit ~/catkin_ws/src/hello_world/CMakeLists.txt file
cd ~/catkin_ws/
catkin build

# run it with
./devel/lib/hello_world/hello_world_node

# or better by registrating in ROS bash environment and rosrun
source devel/setup.bash
rosrun hello_world hello_world_node
```
