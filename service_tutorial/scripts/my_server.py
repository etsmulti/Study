#!/usr/bin/python
# -*- coding:utf-8 -*-

import rospy
from service_tutorial.srv import my_srv, my_srvResponse


def calculation(req):
    rospy.loginfo("reqest: %d, %d", req.a, req.b)
    rospy.loginfo("response: %d", (req.a+req.b))
    return my_srvResponse(req.a+req.b)

def calculate_server():
    rospy.init_node("my_server")
    my_service_server = rospy.Service("my_service", my_srv, calculation)
    rospy.loginfo("Service Server Ready!!!!")

    rospy.spin()

if __name__ == "__main__":
    calculate_server()