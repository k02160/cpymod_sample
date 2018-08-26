#!/usr/bin/python

import sys
import os

#from sample import system

if hasattr(sys, 'gettotalrefcount'):
   sd = os.path.dirname(os.path.abspath(__file__)) + "\\x64\\Debug"
else:
   sd = os.path.dirname(os.path.abspath(__file__)) + "\\x64\\Release"

sys.path.append(sd)

print("sys.path is {0}".format(sys.path))

import mymodule

print('Hello World')

mymodule.echo("hoge")
