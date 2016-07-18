// include ROS C++ headers
#include <ros/ros.h>

// include ROS geometry messages
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv) {
	// announce this node to ROS master as "turtlesim_random_walk" node
  	ros::init(argc, argv, "turtlesim_random_walk");

	// access point to communications with the ROS system, initializes this node
  	ros::NodeHandle nh;

	// broadcast a simple log message
	ROS_INFO("Starting random walk...");
	
	// set up the publisher for the turtle simulator cmd_vel topic, max. 1 message is queued
	ros::Publisher publisher = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1);
	
	// set up publishing rate with 0.5 Hz
	ros::Rate rate(0.5);
	
	while(ros::ok()) {
		geometry_msgs::Twist cmd;
		
		// random numbers between -1 and 1
		cmd.linear.x = (std::rand() % 200) * 0.01 - 1;  // translation along x axis
		cmd.angular.z = (std::rand() % 200) * 0.01 - 1; // rotation around z axis
		
		//publish the command message
      	publisher.publish(cmd);
      	
      	ROS_INFO("Published cmd_vel: linear x = %f, angular z = %f", cmd.linear.x, cmd.angular.z);
		
		// enters a loop and waits for callbacks one time
		ros::spinOnce();
		
		// sleep some duration according to provided rate
		rate.sleep();
	}

	return 0;
}
