#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := app-template
CXXFLAGS := -DARDUINO=100

include $(IDF_PATH)/make/project.mk

