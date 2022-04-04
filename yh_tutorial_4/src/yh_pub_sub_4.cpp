#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h"


// class PubSub()
// {
//     public:
//         const yh_tutorial_4::yh_msg_4::ConstPrt& msg;
//         ros::init(argc, argv, "yh_sub_4");
//         ros::Subscriber yh_sub =  nh.subscribe("yh_topic_4", 100, msgCallback);
//         ros::NodeHandle nh;
//         ros::Publisher yh_pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4",100);

//         void msgCallbak(msg)
// };

ros::Publisher yh_pub;

void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{

    if(msg->data%5 == 0){
        yh_pub.publish(msg);
    }

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_pub_sub_4");
    ros::NodeHandle nh;
    ros::Subscriber yh_sub =  nh.subscribe("yh_topic_4", 100, msgCallback);
    yh_pub = nh.advertise<yh_tutorial_4::yh_msg_4>("temp_topic_4",100);


    ros::spin();

    return 0;

}