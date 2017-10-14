#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv){
  double PI = 3.135;
  ros::init(argc, argv, "drawsquare");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise
    <geometry_msgs::Twist>("turtle1/cmd_vel", 1000);



  ros::Rate rate(1);
  while (ros::ok()){
    geometry_msgs::Twist msg;

    msg.linear.x = double(5);
    msg.angular.z = 0;
    pub.publish(msg);
    rate.sleep();

    msg.linear.x = double(0);
    msg.angular.z = PI/2;
    pub.publish(msg);
    rate.sleep();
  }

}
