#!/usr/bin/python
# -*- coding:utf-8 -*-

import rospy
from yh_tutorial_6.srv import yh_srv_6
import sys

def calculate_client(a, b, c):
    rospy.wait_for_service("yh_service_6")
    try:
        yh_service_6_client = rospy.ServiceProxy("yh_service_6", yh_srv_6)
        resp = yh_service_6_client(a, b, c)
        return resp.result
    except rospy.ServiceException as e:
        rospy.logerr("Service call faile: %s", e)

if __name__ == "__main__":
    rospy.init_node("yh_client_6")
    if len(sys.argv) != 4:
        rospy.loginfo("usage: rosrun yh_tutorial_7 yh_client.py a b c")
        rospy.loginfo("a, b, c : int 64 number")
        sys.exit(1)

    a = int(sys.argv[1])
    b = int(sys.argv[2])
    c = int(sys.argv[3])
    res = calculate_client(a, b, c)

    rospy.loginfo("send: a = %d, b = %d, c = %d", a, b, c)
    rospy.loginfo("receive: result = %d", res)
