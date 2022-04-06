#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"

int sum = 0;

void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->stamp.nsec);
    ROS_INFO("receive msg = %d", msg->data);

    sum = sum + msg->data;

    printf("정수의 합은 sum : %d \n", sum);

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_sum_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub =  nh.subscribe("yh_sum_topic", 100, msgCallback);

    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}

