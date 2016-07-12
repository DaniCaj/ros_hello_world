Hello World example for ROS Indigo.

# Compile it manually (without creating a package)

```
$ g++ src/hello_world/src/hello_world.cpp -o hello_world.out -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole
```

# Compile it with catkin tools
```
$ catkin build
```
