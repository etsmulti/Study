#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_pub_4");
    ros::NodeHandle nh;

    ros::Publisher yh_pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4",100);

    ros::Rate loop_rate(10);

    yh_tutorial_4::yh_msg_4 msg;

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