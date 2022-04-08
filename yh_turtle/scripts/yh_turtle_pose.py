#!/home/min/anaconda3/bin/python
# -*- coding: utf8 *-*

from xml.etree.ElementTree import PI
import rospy
from geometry_msgs.msg import Twist
import math
import turtlesim.srv
from turtlesim.msg import Pose

def update_pose(data):
    pose = data
    pose.x = round(pose.x, 4)
    pose.y = round(pose.y, 4)
    print(f'pos.x : {pose.x}, pos.y : {pose.y} ')


def talker():
    rospy.init_node("yh_tutle_circle")
    pub = rospy.Publisher("/turtle2/cmd_vel", Twist, queue_size=100)
    msg = Twist()

    r = input("원의 반지름을 입력하세요 : ")
    l = float(r)

    z = 2 * 3.14159 / 10.0
    msg.linear.x =  2 * 3.14159 * l / 10
    msg.angular.z = z

    loop_rate = rospy.Rate(1)

    rospy.wait_for_service('spawn')
    spawner = rospy.ServiceProxy('spawn', turtlesim.srv.Spawn)
    spawner(5.5, 5.5 - l, 0, 'turtle2')

    sub_pose = rospy.Subscriber('/turtle2/pose', Pose, update_pose)

    pose = Pose()
 
    while not rospy.is_shutdown():    
        pub.publish(msg)
        loop_rate.sleep()
        print()

if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

