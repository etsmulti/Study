#!/usr/bin/python
# -*- coding: utf-8 -*-


""" 필수 상황

#!/usr/bin/python
# -*- coding: utf-8 -*-
한글을 쓸며면 이렇게 해야 됩니다. 
 """

import rospy
from yh_tutorial_2.msg import yh_msg_2

def talker():
   
    pub = rospy.Publisher("yh_topic_2",yh_msg_2,queue_size=100)
    rospy.init_node("py_yh_pub_2",anonymous=True)
    loop_rate = rospy.Rate(5)
    cnt = 0
    msg = yh_msg_2()


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