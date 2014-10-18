#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import platform
import buildbase

class BuildJourney(buildbase.BuildBase):

    @staticmethod
    def getName():
        return 'j'

    def interName(self):
        return BuildCMake.getName()

    def __init__(self, nWorkspace, nNo):
        self.mWorkspace = nWorkspace
        self.mNo = nNo
        self.__initChdir()

    def __initChdir(self):
        cmdPath = '../%s/binary/' % self.mWorkspace
        buildbase.BuildBase.runChdir(self, cmdPath)

    def insertBuildParameter(self, nBuildParameter):
        self.mJourneyPath = '../journey/journey_%s' % self.mNo
        self.mJourneyPath = os.path.abspath(self.mJourneyPath)
        
    def runBuild(self):
        journeyCmd = 'journey.exe %s' % self.mJourneyPath
        sysName = platform.system()
        if 'Windows' != sysName:
            journeyCmd = './journey %s' % self.mJourneyPath
        buildbase.BuildBase.interBuild(self, journeyCmd)
