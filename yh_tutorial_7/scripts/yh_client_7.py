#!/usr/bin/python
# -*- coding:utf-8 -*-

import rospy
from yh_tutorial_7.srv import yh_srv_7
import sys

def calculate_client(a, b):
    rospy.wait_for_service("yh_service_7")
    try:
        yh_service_7_client = rospy.ServiceProxy("yh_service_7", yh_srv_7)
        resp = yh_service_7_client(a, b)
        return resp.result
    except rospy.ServiceException as e:
        rospy.logerr("Service call faile: %s", e)

if __name__ == "__main__":
    rospy.init_node("yh_client_7")
    if len(sys.argv) != 3:
        rospy.loginfo("usage: rosrun yh_tutorial_7 yh_client.py a b ")
        rospy.loginfo("a, b: int 64 number")
        sys.exit(1)

    a = int(sys.argv[1])
    b = int(sys.argv[2])
    res = calculate_client(a, b)

    rospy.loginfo("send: a = %d, b = %d", a, b)
    rospy.loginfo("receive: result = %d", res)
