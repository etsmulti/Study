#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"

int sum = 0;

class MyClass
{
    public:
        MyClass()
        {
            sub = nh.subscribe("yh_sum_topic", 100, &MyClass::msgCallback, this);
        }

        void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg); 


        // void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
        // {
        //     ROS_INFO("receive msg = %d", msg->stamp.sec);
        //     ROS_INFO("receive msg = %d", msg->stamp.nsec);
        //     ROS_INFO("receive msg = %d", msg->data);
        //     sum = sum + msg->data;
        //     printf("정수의 합은 sum : %d \n", sum);
        // }

    private:
        ros::NodeHandle nh;
        ros::Subscriber sub;
        int sum = 0;

};

void MyClass::msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
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
    
    MyClass my_class;
    // ros::NodeHandle nh;
    // ros::Subscriber sub =  nh.subscribe("yh_sum_topic", 100, msgCallback);
    ros::spin();  //프로그램 종료 방지 대기
    return 0;
}


