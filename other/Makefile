
NAME := other.a
FANCY_NAME := Engine/other

################################################################

DIR_SRC := src/
DIR_OBJ := obj/

################################################################

FILES := \

################################################################

FILES += \
	PolyGon/PolyGon.cpp \
\
	PolyGon/Graphics/Full/Main/Data.cpp \
	PolyGon/Graphics/Full/Main/Layout.cpp \
	PolyGon/Graphics/Full/ShaderLayout.cpp \
\
	PolyGon/Graphics/Wire/Main/Layout.cpp \
	PolyGon/Graphics/Wire/ShaderLayout.cpp \
\
	PolyGon/InstanceManager.cpp \
	PolyGon/ObjectData.cpp \
	PolyGon/Manager.cpp \
	PolyGon/Object.cpp \

################################################################

FILES += \
	PolyHedra/Data.cpp \
	PolyHedra/PolyHedra.cpp \
	PolyHedra/FileCollection.cpp \
	PolyHedra/Parser.cpp \
	PolyHedra/Generate.cpp \
\
	PolyHedra/Skin/Data.cpp \
	PolyHedra/Skin/Skin.cpp \
	PolyHedra/Skin/Parsing.cpp \

################################################################

#FILES += \
#	Wavefront/OBJ.cpp \
#	Wavefront/Main/Data.cpp \
#	Wavefront/Main/Buffer.cpp \
#	Wavefront/Simple3D/BufferArray.cpp \
#	Wavefront/Simple3D/Shader.cpp \
#	Wavefront/MTL.cpp \

################################################################

LIBRARYS  := $(NAME)
INCLUDES  := include/ ../ValueType/include ../Generics/include ../FileManager/include ../OpenGL/include ../Display/include ../Graphics/include ../User/include
ARGUMENTS := -D ENGINE_DIR='"$(shell pwd)"'

################################################################

BASE_DIR := ../

include $(BASE_DIR)/MakefileArchiver.mk

################################################################
