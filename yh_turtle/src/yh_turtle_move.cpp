#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char** argv )
{
    ros::init(argc, argv, "yh_turtle_move");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);

    ros::Rate loop_rate(1);

    geometry_msgs::Twist msg;

    msg.angular.z = 1;

    while(ros::ok())
    {
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}

