#include "ros/ros.h"
#include "yh_tutorial_2/yh_msg_2.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_pub_2");
    ros::NodeHandle nh;


    ros::Publisher yh_pub = nh.advertise<yh_tutorial_2::yh_msg_2>("yh_topic_2", 100);

    ros::Rate loop_rate(5);

    yh_tutorial_2::yh_msg_2 msg;

    int cnt = 0;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;
        ROS_INFO("send msg = %d", msg.stamp.sec);
        ROS_INFO("send msg = %d", msg.stamp.nsec);
        ROS_INFO("send msg = %d", msg.data);
        cnt++;
        yh_pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;

}