#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h"


void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{

    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->data);

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_sub_4");
    ros::NodeHandle nh;
    
    ros::Subscriber yh_sub =  nh.subscribe("temp_topic_4", 100, msgCallback);
    ros::spin();
    return 0;

}

