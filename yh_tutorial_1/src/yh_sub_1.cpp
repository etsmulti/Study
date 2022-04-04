#include "ros/ros.h"
#include "yh_tutorial_1/yh_msg_1.h"


void msgCallback(const yh_tutorial_1::yh_msg_1::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->data);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_sub_1");
    ros::NodeHandle nh;

    ros::Subscriber yh_sub =  nh.subscribe("yh_topic_1", 100, msgCallback);

    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}

