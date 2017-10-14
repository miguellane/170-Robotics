#include <ros/ros.h>
#include <turtlesim/Color.h>
#include <iomanip>

void colorMessageReceived(const turtlesim::Color& msg){
  ROS_INFO_STREAM("Red:" << (unsigned int)msg.r << " Green:" << (unsigned int)msg.g << " Blue:" << (unsigned int)msg.b);
  ROS_ERROR_STREAM("Red:" << (unsigned int)msg.r << " Green:" << (unsigned int)msg.g << " Blue:" << (unsigned int)msg.b);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "printcolor");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("turtle1/color_sensor", 1000, &colorMessageReceived);
  ros::spin();
}
