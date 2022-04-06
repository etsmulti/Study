#!/usr/bin/python
# -*- conding:utf-8 -*-

import rospy
from yh_tutorial_7.srv import yh_srv_7, yh_srv_7Response

def calculation(req):
    rospy.loginfo("request: a = %d, b = %d", req.a, req.b)
    rospy.loginfo("response: %d", abs(req.a - req.b))
    return yh_srv_7Response(abs(req.a - req.b))

def calculate_server():
    rospy.init_node("yh_server_7")
    server_7_service_server = rospy.Service("yh_service_7", yh_srv_7, calculation)
    rospy.loginfo("yh_tutorial_7 Service Server Ready !!!!")

    rospy.spin()

if __name__ == "__main__":
    calculate_server()