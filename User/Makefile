
NAME := User.a
FANCY_NAME := Engine/User

################################################################

DIR_SRC := src/User/
DIR_OBJ := obj/User/

################################################################

FILES := \
\
	Enums/Modifier.cpp \
	Enums/Action.cpp \
	Enums/State.cpp \
	Enums/MouseButtons.cpp \
	Enums/Keys.cpp \
\
	Args/KeyArgs.cpp \
	Args/TextArgs.cpp \
	Args/ClickArgs.cpp \
	Args/DragArgs.cpp \
	Args/MoveArgs.cpp \
	Args/ScrollArgs.cpp \
\
	KeyState.cpp \
	MouseState.cpp \
	MouseManager.cpp \
	KeyBoardManager.cpp \

################################################################

FILES += \
	../FrameTime.cpp \
	../Window.cpp \

################################################################

LIBRARYS  := $(NAME)
INCLUDES  := include/ ../Debug/include ../ValueType/include ../Generics/include ../FileManager/include ../OpenGL/include ../Display/include
ARGUMENTS := -D ENGINE_DIR='"$(shell pwd)"'

################################################################

BASE_DIR := ../

include $(BASE_DIR)/MakefileArchiver.mk

################################################################
