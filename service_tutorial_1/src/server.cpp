#include "ros/ros.h"  //ROS 해버파일
#include "service_tutorial_1/my_srv_1.h" //서비스 해더 파일 // 빌드후 생성

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operator = PLUS;
// 서비스 요청이 있을 경우 호출되는 함수
// 서비스 요청은 req, 서비스 응답은 req로 설정
bool calculation(service_tutorial_1::my_srv_1::Request &req, service_tutorial_1::my_srv_1::Response &res)
{
    switch(my_operator)
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            if( req.b == 0)
            {
                printf("Can't divide by 0 다른 숫자를 입력하세요  ");
                break;
            }
            else {
            res.result = req.a / req.b;
            }

            break;
        default:
            res.result = req.a + req.b;
            break;
       
    }

    // 서비스 요청에 사용된 a, b 출력, 서비스 응담 result 값 출력
    ROS_INFO("request: a= %ld, b=%ld", req.a, req.b);
    ROS_INFO("response: %ld", res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "my_server_1");
    ros::NodeHandle nh;

    nh.setParam("calculation_method", PLUS);

    // 서비스 선언
    // 서비스 서버 (my_service_server)를 선언한다.
    // 서비스 이름은 (my_service_1)이고 요청이 있을 때 (calculation)을 실행한다.
    // (service_tutorial_1) 패키지의 (my_srv_1) 서비스 파일을 이용한다.
    ros::ServiceServer my_service_server = nh.advertiseService("my_service_1", calculation);

    ROS_INFO("Service Server Ready!!");
    // ros::spin(); //서비스 요청 대기 하면서 spinOnce()만 실행한다.
    // ros::spin();  => while(true){ros::spinOnce();}
    
    ros::Rate loop_rate(10);
    while(true)
    {
        nh.getParam("calculation_method", my_operator);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}