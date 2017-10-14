#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Char.h>

char key = 'X';
float theta;

void charMessageReceived(const std_msgs::Char& msg){
  key = msg.data;
}
void poseMessageReceived(const turtlesim::Pose& msg){
  theta = (float)msg.theta;
}

int main(int argc, char **argv){
  ros::init(argc, argv, "moveongrid");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  ros::Subscriber sub1 = nh.subscribe("commands", 1000, &charMessageReceived);
  ros::Subscriber sub2 = nh.subscribe("turtle1/pose", 1000, &poseMessageReceived);
  double PI = 3.14159265;
  double rot;
  ros::Rate rate(1);
  while(ros::ok()){
    geometry_msgs::Twist msg;
    ros::spinOnce();
//    ROS_ERROR_STREAM("Key " << key << " Theta " << theta);
//(int)(2*want/PI - 2*theta/PI )
    switch(key){
      case 'U': rot = PI/2 - theta; break;
      case 'L': rot = PI - theta; break;
      case 'D': rot = 3*PI/2 - theta; break;
      case 'R': rot = 2*PI - theta; break;
    }
    if(key != 'X'){    
      rate.reset();
      msg.angular.z = rot;
      pub.publish(msg);
      rate.sleep();
      msg.angular.z = 0;
      
      rate.reset();
      msg.linear.x = double(1);
      pub.publish(msg);
      rate.sleep();
    }
    key = 'X';
  }
}
