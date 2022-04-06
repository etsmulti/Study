#include "ros/ros.h"
#include "yh_divisor/yh_divisor_msg.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_divisor_pub");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<yh_divisor::yh_divisor_msg>("yh_divisor_topic", 100);

    ros::Rate loop_rate(1);

    yh_divisor::yh_divisor_msg msg;

    int cnt = 0;

    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        msg.data = cnt;
        ROS_INFO("send msg = %d", msg.stamp.sec);
        ROS_INFO("send msg = %d", msg.stamp.nsec);
        ROS_INFO("send msg = %d", msg.data);
        cnt++;
        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;

}