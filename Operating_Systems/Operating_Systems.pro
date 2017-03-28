TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS +=-lpthread
CONFIG += link_pkgconfig
PKGCONFIG += gtk+-3.0

DISTFILES += \
    ASC16 \
    write \
    read

HEADERS += \
    lvm_assembler.h \
    lvm_global.h \
    lvm_lmachine.h \
    OS_Bitmap.h \
    OS_File.h \
    OS_Global.h \
    soo_ast.h \
    soo_global.h \
    soo_parse.h \
    soo_token.h \
    Command.h \
    Instruction_Operation.h

SOURCES += \
    lvm_assembler.cpp \
    lvm_global.cpp \
    lvm_lmachine.cpp \
    OS_Bitmap.cpp \
    OS_File.cpp \
    OS_Global.cpp \
    OS_Main.cpp \
    soo_ast.cpp \
    soo_global.cpp \
    soo_parse.cpp \
    soo_token.cpp \
    window.cpp \
    Command.cpp \
    Instruction_Operation.cpp



