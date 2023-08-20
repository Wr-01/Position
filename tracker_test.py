import triad_openvr
import time
import sys
import datetime

v = triad_openvr.triad_openvr()
v.print_discovered_objects()

if len(sys.argv) == 1:
    interval = 1/60
elif len(sys.argv) == 2:
    interval = 1/float(sys.argv[0])
else:
    print("Invalid number of arguments")
    interval = False

def saveTxt(path,data):
    with open(path, 'a+') as f:
        f.write(data +'\n')

if interval:
    while(True):
        start = time.time()
        txt = ""
        for each in v.devices["tracker_1"].get_pose_euler():
            txt += "%.6f" % each
            txt += " "



        #time_local = time.localtime(timestamp / 1000)
        #time_local = time.localtime(time.time())
        # # 转换成新的时间格式(2016-05-05 20:28:54)
        # otherStyleTime = time.strftime("%Y-%m-%d %H:%M:%S", time_local)
        #dt_ms = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')
        #d = datetime.datetime.fromtimestamp(time_local / 1000)
        # dt = time.strftime("%Y%m%d%H%M%S", time_local)

        #saveTxt(r'./info.txt',txt + str(time.time()/3600000))
        saveTxt(r'C:\Users\19261\Desktop\2.txt',txt + str(time.time()))
        #saveTxt(r'C:\Users\19261\Desktop\1.txt',txt + str(dt_ms))
        print("\r" + txt +str(time.time()), end="")
        #sleep_time = interval-(time.time()-start)
        #if sleep_time>0:
            #time.sleep(sleep_time)