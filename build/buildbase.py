#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os
import subprocess

class BuildBase():

    def runChdir(self, nCmdPath):
        self.mCmdPath = os.path.abspath(nCmdPath)
        if not os.path.isdir(self.mCmdPath):
            os.mkdir(self.mCmdPath)
        os.chdir(self.mCmdPath)

    def interBuild(self, nCmd):
        subprocess.call(nCmd, shell=True)
