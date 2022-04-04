#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from topic_tutorial.msg import my_msg

def talker():
   
    pub = rospy.Publisher("my_topic",my_msg,queue_size=100)
    rospy.init_node("py_publisher",anonymous=True)
    loop_rate = rospy.Rate(10)
    cnt = 0
    msg = my_msg()


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