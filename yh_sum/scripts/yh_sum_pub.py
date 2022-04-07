#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_sum.msg import yh_sum_msg

def talker():
   
    pub = rospy.Publisher("yh_sum_topic",yh_sum_msg,queue_size=100)
    rospy.init_node("yh_sum_pub",anonymous=True)
    loop_rate = rospy.Rate(10)
    cnt = 0
    msg = yh_sum_msg()


    while not rospy.is_shutdown():
        msg.stamp = rospy.get_rostime()
        msg.data = cnt 
        rospy.loginfo("send message: %d", msg.stamp.secs)
        rospy.loginfo("send message: %d", msg.stamp.nsecs)
        rospy.loginfo("send message: %d", msg.data)

        cnt += 1
        pub.publish(msg)
        loop_rate.sleep() 
        
if __name__=="__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass