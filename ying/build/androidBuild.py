import os
import subprocess

print 'welcome to build of android'

includePath = os.path.abspath('../Include')
os.environ['WANMEI_INCLUDE'] = includePath

cmdPath = os.path.abspath('../../mbclient')
os.chdir(cmdPath)

cmakeCmd = 'cocos compile -p android -j 4 --ap 15'
subprocess.call(cmakeCmd, shell=True)

print 'finish build of android, byebye!'
