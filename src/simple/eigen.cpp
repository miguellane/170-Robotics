#include <ros/ros.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <iomanip>

#include <amcl/pf/eig3.h>

void poseCallback(const geometry_msgs::PoseWithCovarianceStamped& msg){
  ROS_INFO_STREAM("Vo");
  ROS_INFO_STREAM(msg.pose.covariance);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "eigen");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("/amcl_pose", 1000, &poseCallback);
  ros::spin();
}

