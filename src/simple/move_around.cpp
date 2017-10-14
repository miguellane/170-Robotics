#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>

#include <geometry_msgs/Twist.h>

void odomMessageReceived(const nav_msgs::Odometry& msg){
  ROS_INFO_STREAM(msg);
}
void imuMessageReceived(const sensor_msgs::Imu& msg){
  ROS_INFO_STREAM(msg);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "move_around");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("mobile_base/commands/velocity", 1000);
  ros::Subscriber sub1 = nh.subscribe("odom", 1000, &odomMessageReceived);
  ros::Subscriber sub2 = nh.subscribe("mobile_base/sensors/imu_data", 1000, &imuMessageReceived);
  double PI = 3.14159265;
  ros::Rate rate(1);
  while(ros::ok()){
    geometry_msgs::Twist msg;
    ros::spinOnce();
    rate.reset();
      msg.linear.x = 0;
      msg.angular.z = PI/2;
      pub.publish(msg);
    rate.sleep();
    rate.reset();
      msg.linear.x = double(1);
      msg.angular.z = 0;
      pub.publish(msg);
    rate.sleep();
  }
}
