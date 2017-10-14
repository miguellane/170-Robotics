#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Char.h>

char command;

void commandReceived(const std_msgs::Char&msg) {
    command = msg.data;
    ROS_ERROR_STREAM("Received character " << command);
}

int main(int argc,char **argv) {

    ros::init(argc,argv,"followplan");
    ros::NodeHandle nh;
    ros::Publisher pub =nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",1000);
    ros::Subscriber sub = nh.subscribe("commands",1000,&commandReceived);

    ros::Rate rate(1);
    command = ' ';
    geometry_msgs::Twist msg;
    ROS_ERROR_STREAM("Followplan up and running...");
    
    while (ros::ok()) {
	ROS_ERROR_STREAM("Waiting for a command");
	while ( command != 'F' && command != 'B' && command !='L' && command != 'R' ){
	    ros::spinOnce();
	}
	ROS_ERROR_STREAM("Received valid  command " << command);
	switch (command) {
	case 'F':
	    msg.linear.x = 1;
	    msg.angular.z = 0;
	    break;
	case 'B':
	    msg.linear.x = -1;
	    msg.angular.z = 0;
	    break;
	case 'L':
	    msg.linear.x = 0;
	    msg.angular.z = M_PI/2;
	    break;
	case 'R':
	    msg.linear.x = 0;
	    msg.angular.z = -M_PI/2;
	    break;
	}
	rate.reset();
	pub.publish(msg);
	rate.sleep();
	command = ' ';

	msg.linear.x = 0;
	msg.angular.z = 0;
	pub.publish(msg); // stop the robot

    }

}
