#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Pose.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

float x;
float y;
float theta;

void poseMessageReceived(const turtlesim::Pose&msg) {
   x = msg.x;
   y = msg.y;
   theta = msg.theta;
}

int main(int argc,char ** argv) {

  ros::init(argc,argv,"republishpose");
  ros::NodeHandle nh;
  ros::Subscriber subPose =
    nh.subscribe("turtle1/pose",1000,&poseMessageReceived);
  ros::Publisher pub =
    nh.advertise<geometry_msgs::Pose>("pose",1000);
  geometry_msgs::Pose poseToPublish;
  tf2::Quaternion q;
  
  while (ros::ok()) {
    ros::spinOnce();
    poseToPublish.position.x = x;
    poseToPublish.position.y = y;
    poseToPublish.position.z = 0;
    q.setRPY(0,0,theta);
    poseToPublish.orientation = tf2::toMsg(q);   
    pub.publish(poseToPublish);
  }
}
