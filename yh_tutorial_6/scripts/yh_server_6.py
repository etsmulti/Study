#!/usr/bin/python
# -*- conding:utf-8 -*-

import rospy
from yh_tutorial_6.srv import yh_srv_6, yh_srv_6Response

def calculation(req):
    rospy.loginfo("request: a = %d, b = %d, c = %d ", req.a, req.b, req.c)
    rospy.loginfo("response: %d", (req.a +req.b +req.c))
    return yh_srv_6Response(req.a+req.b+req.c)

def calculate_server():
    rospy.init_node("yh_server_6")
    server_6_service_server = rospy.Service("yh_service_6", yh_srv_6, calculation)
    rospy.loginfo("yh_tutorial_6 Service Server Ready !!!!")

    rospy.spin()

if __name__ == "__main__":
    calculate_server()