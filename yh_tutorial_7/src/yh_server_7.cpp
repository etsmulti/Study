#include "ros/ros.h"  //ROS 해버파일
#include "yh_tutorial_7/yh_srv_7.h" //서비스 해더 파일 // 빌드후 생성

// 서비스 요청이 있을 경우 호출되는 함수
// 서비스 요청은 req, 서비스 응답은 req로 설정
bool calculation(yh_tutorial_7::yh_srv_7::Request &req, yh_tutorial_7::yh_srv_7::Response &res)
{
    // 서비스 요청시 받은 a와 b 값을 더하여 서비스 응답 값에 저장한다.  
    res.result = abs(req.a - req.b);

    // 서비스 요청에 사용된 a, b 출력, 서비스 응담 result 값 출력
    ROS_INFO("request: a= %ld, b=%ld", req.a, req.b);
    ROS_INFO("response: %ld", res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_server_7");
    ros::NodeHandle nh;

    // 서비스 선언
    // 서비스 서버 (my_service_server)를 선언한다.
    // 서비스 이름은 (my_service)이고 요청이 있을 때 (calculation)을 실행한다.
    // (service_tutorial) 패키지의 (my_srv) 서비스 파일을 이용한다.
    ros::ServiceServer yh_server_7 = nh.advertiseService("yh_service_7", calculation);

    ROS_INFO("Service Server Ready!!");
    ros::spin(); //서비스 요청 대기
    return 0;
}