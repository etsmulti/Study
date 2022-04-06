#!/usr/bin/python
# -%- coding:utf-8 -*-

import rospy
from yh_tutorial_5.srv import yh_srv_5, yh_srv_5Response

def calculation(req):
    rospy.loginfo("request: %d, %d", req.a, req.b)
    rospy.loginfo("response: %d", (req.a * req.b) )
    return yh_srv_5Response(req.a*req.b)

def calculate_server():
    rospy.init_node("yh_server_5")
    srv5_service_server = rospy.Service("yh_service_5", yh_srv_5, calculation)
    rospy.loginfo("yh_tutorial_5 Sevice Server Readly!!!")

    rospy.spin()

if __name__ == "__main__":
    calculate_server()