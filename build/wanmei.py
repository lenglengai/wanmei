import buildbase
import buildcmake
import buildide

class Startup():

    def runInit(self):
        buildCMake = BuildCMake()
        mBuildBases[buildCMake.getName()] = buildCMake

        buildIDE = BuildIDE()
        mBuildBases[buildCMake.getName()] = buildCMake

myClass2 = MyClass2()
dict1[myClass2.getName()] = myClass2

    mBuildBases = {};

if __name__ == '__main__':
