#include "ros/ros.h"
#include "topic_tutorial/my_msg.h" //my_msg 파일 헤더 //빌드 후 자동 생성

    /*
    class Bclass {
        int c = 10;
    }
    Bclass b;
    printf("%d", b.c);

    Bclass *a = &b;
    
    printf("%d", *a.c);
    printf("%d", a->c);
    *a.c == a->c  */

// 메시지 콜백함수, 서브스크라이버가 메시지를 수행했을 때 동작하는 함수이다.
// 입력메시지로서 패키지 이름 (topic_tutorial)의 메시지 이름 (my_msg)을 받도록 되어있다.

void msgCallback(const topic_tutorial::my_msg::ConstPtr& msg)  //& call by reference를 쓴다
{

    ROS_INFO("receive msg = %d", msg->stamp.sec);  // stamp.sec를 표시한다
    ROS_INFO("receive msg = %d", msg->stamp.nsec);  // stamp.sec를 표시한다
    ROS_INFO("receive msg = %d", msg->data);  // data를 표시한다

}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_subscriber"); // 노드 이름 초기화
    ros::NodeHandle nh; // ros 시스템과 통신을 위한 노드 해들 선언

    // 서브스크라이버 선언
    // 패키지 (topic_tutorial)의 메시지(my_msg)을 이용한 서브스크라이버(my_sub)를 적성한다.
    // 토픽명은 (my_topic)이며, 서브스크라이버큐(queue) 사이즈를 100으로 설정한다.
    // 콜백 함수는 (msgCallback)이다.
    ros::Subscriber my_sub = nh.subscribe("my_topic", 100, msgCallback);  // 메세지를 받을 callback 함수를 적어준다.

    // 콜백 함수 호출을 위한 함수, 메시지가 수신되기를 대기
    // 수신되었을 경우 콜백 함수를 호줄한다.
    ros::spin();

    return 0;
}