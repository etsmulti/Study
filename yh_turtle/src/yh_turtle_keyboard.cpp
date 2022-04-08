#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

ros::Publisher pub;

void keyboardCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    pub.publish(msg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_tutle_keyboard");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/cmd_vel", 1, keyboardCallback);
    pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    ros::spin();
    return 0;

}