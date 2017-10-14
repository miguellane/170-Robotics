#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Char.h>

ros::Publisher pub;

void charMessageReceived(const std_msgs::Char& msg){
  char data = msg.data;

  double PI = 3.14159265;
  geometry_msgs::Twist msg2;
//  ROS_ERROR_STREAM("Red:" << (unsigned int)msg.r << " Green:" << (unsigned int)msg.g << " Blue:" << (unsigned int)msg.b);
  ros::Rate rate(1);
  rate.reset();
  switch(data){
    case 'F': msg2.linear.x = double(1); msg2.angular.z = double(0); break;
    case 'B': msg2.linear.x = -double(1); msg2.angular.z = double(0); break;
    case 'L': msg2.linear.x = double(0); msg2.angular.z = PI / 2;    break;
    case 'R': msg2.linear.x = double(0); msg2.angular.z = -PI / 2;    break;
  }
  pub.publish(msg2);
  rate.sleep();

}

int main(int argc, char **argv){
  ros::init(argc, argv, "followplan");
  ros::NodeHandle nh;
  pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

  ros::Subscriber sub = nh.subscribe("commands", 1000, &charMessageReceived);

  ros::spin();
}
