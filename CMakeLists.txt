project(pybind_test)
cmake_minimum_required(VERSION 3.20)
find_package(PythonLibs REQUIRED)
include_directories(pybind11/include)
set(CMAKE_BUILD_TYPE Debug)

set(variables
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS_MINSIZEREL
	)

foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
		string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
endforeach()

include_directories(${PYTHON_INCLUDE_DIRS})
add_library(bind SHARED bind.cpp)
set_target_properties(bind PROPERTIES SUFFIX ".pyd")
target_link_libraries(bind ${PYTHON_LIBRARIES})

add_library(bind2 SHARED bind2.cpp)
set_target_properties(bind2 PROPERTIES SUFFIX ".pyd")
target_link_libraries(bind2 ${PYTHON_LIBRARIES})

add_custom_command(OUTPUT output_pyd
   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bind.pyd ${CMAKE_BINARY_DIR}/../pac/bind.pyd
   )
add_custom_command(OUTPUT output_pyd2
   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bind2.pyd ${CMAKE_BINARY_DIR}/../pac/pac2/bind2.pyd
   )
add_custom_target(CopyTask ALL DEPENDS output_pyd bind output_pyd2 bind2)