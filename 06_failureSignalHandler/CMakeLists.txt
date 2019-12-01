set(MODULE_NAME 06_failureSignalHandler)
project(${MODULE_NAME})

file(GLOB sources     "*.cpp")
file(GLOB headers_hpp "*.hpp")
file(GLOB headers_h   "*.h")
list(APPEND headers ${headers_h} ${headers_hpp})

add_executable(${MODULE_NAME}
	${sources}
	${headers}
)

# set the Visual Studio Command Arguments
IF(WIN32)
	set_property(TARGET ${MODULE_NAME} PROPERTY VS_DEBUGGER_COMMAND_ARGUMENTS "--vmodule=test_vlog=2,main=1 --v=0")
ENDIF()

target_link_libraries(${MODULE_NAME}
	glog::glog
)