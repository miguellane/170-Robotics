#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <nav_msgs/GetPlan.h>

int main(int argc,char **argv) {

    ros::init(argc,argv,"serviceclient");

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<nav_msgs::GetPlan>("/move_base/make_plan");
    client.waitForExistence();
    
    nav_msgs::GetPlan service;

    service.request.start.header.frame_id = "map";
    service.request.start.header.stamp = ros::Time::now();
    service.request.start.pose.position.x = 0;
    service.request.start.pose.position.y = 0;
    service.request.start.pose.orientation.w = 1.0;

    service.request.goal.header.frame_id = "map";
    service.request.goal.header.stamp = ros::Time::now();
    service.request.goal.pose.position.x = 1;
    service.request.goal.pose.position.y = 1;
    service.request.goal.pose.orientation.w = 90.0;
    
    if (client.call(service)) {
	ROS_ERROR_STREAM("Service successfully called");
//	ROS_INFO_STREAM("Status_message:" << service.response.status_message);
//	ROS_INFO_STREAM("Success flag:" << service.response.success);
    }
    else {
	ROS_ERROR_STREAM("Error while calling service");
//	ROS_ERROR_STREAM("Status_message:" << service.response.status_message);
//	ROS_ERROR_STREAM("Service success:" << service.response.success);
    }

    return 0;
}
