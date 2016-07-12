// include ROS C++ headers
#include <ros/ros.h>

int main(int argc, char** argv) {
	// announce this node to ROS master as "hello_world" node
  	ros::init(argc, argv, "hello_world");

	// access point to communications with the ROS system, initializes this node
  	ros::NodeHandle nh;

	// broadcast a simple log message
	ROS_INFO_STREAM("Hello World!");

	// enters a loop and waits for callbacks, until receiving a SIGINT (ctrl-c)
	ros::spin();

	return 0;
}
