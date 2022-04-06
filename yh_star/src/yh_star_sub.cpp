#include "ros/ros.h"
#include "yh_star/yh_star_msg.h"


void msgCallback(const yh_star::yh_star_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->stamp.sec);
    ROS_INFO("receive msg = %d", msg->stamp.nsec);
    ROS_INFO("receive msg = %d", msg->data);

    for(int i= 1; i <= msg->data; i++)
    {
        if (msg->data / 2 >= i) 
        {
            for(int j = 0; j < i; j++)
            {
                printf("*");
            }
        }
        else
        {
            for(int j = 0; j < msg->data - i; j++)
            {
                printf("*");
            }
        }
        printf("\n");        
    }
    
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_star_sub");
    ros::NodeHandle nh;

    ros::Subscriber sub =  nh.subscribe("yh_star_topic", 100, msgCallback);

    ros::spin();  //프로그램 종료 방지 대기

    return 0;

}

