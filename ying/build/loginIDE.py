import os
import sys

print 'welcome to build of login'

sys.path.append('../../build')
import cmakeBuild

binNick = 'login'
includePath = os.path.abspath('../Include')

cmakeBuild.runBuild(includePath, binNick, True)
