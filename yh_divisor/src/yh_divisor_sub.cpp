#include "ros/ros.h"
#include "yh_divisor/yh_divisor_msg.h"


void msgCallback(const yh_divisor::yh_divisor_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->stamp.nsec);
    ROS_INFO("receive msg = %d", msg->data);

    for(int i= 1; i <= msg->data; i++)
    {
        if (msg->data % i == 0 ) 
        {
            printf("%d, ", i);

        }
    }
    printf("\n");
    
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_divisor_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub =  nh.subscribe("yh_divisor_topic", 100, msgCallback);

    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}

