#
# Copyright (c) 2014 Limit Point Systems, Inc. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# Prerequisite Discovery
#
# This file is included in the top level CmakeLists.txt file, hence any prereq
# discovered and included here will be visible to the entire system.
#

find_package(Doxygen)

if(DOXYGEN_FOUND)
    configure_file(${CMAKE_MODULE_PATH}/dev_doxyfile.cmake.in 
        ${CMAKE_BINARY_DIR}/dev_doxyfile)
    configure_file(${CMAKE_MODULE_PATH}/user_doxyfile.cmake.in 
        ${CMAKE_BINARY_DIR}/user_doxyfile)
    set(DOC_TARGETS ON CACHE BOOL "ON to generate doc targets")
else()
    message(WARNING "Doxygen was not found. Documentation will not be generated.")
endif()

# Tell hdf to use static libs
set(HDF5_USE_STATIC_LIBRARIES ON)

find_package(HDF5 REQUIRED)
if(HDF5_FOUND)
    configure_file(${CMAKE_MODULE_PATH}/hdf_definitions.cmake.in ${CMAKE_BINARY_DIR}/hdf_definitions.cmake)
    include(${CMAKE_BINARY_DIR}/hdf_definitions.cmake)
    include_directories(${HDF5_INCLUDE_DIRS})
    get_filename_component(__TMP_DIR "${HDF5_LIBRARIES}" PATH)
    set(HDF5_LIBRARY_DIR "${__TMP_DIR}" CACHE PATH "" FORCE)
    link_directories(${HDF5_LIBRARY_DIR})

endif()

# Find gnuplot
if(LINUX64GNU OR LINUX64INTEL)
    # Needed for some checks
    find_package(Gnuplot)
    if(GNUPLOT_FOUND)
        message(STATUS "Found Gnuplot")
    endif()
endif()


if(BUILD_SHEAFSCOPE OR BUILD_BINDINGS)
    # Find the JDK
    find_package(Java 1.7 REQUIRED)
    find_package(JNI)
    if(JAVA_FOUND)
        set(JAVA_BINDING_COMPILE_OPTIONS 
            "-I${JNI_INCLUDE_DIRS}" "-I${JAVA_INCLUDE_PATH}" "-I${JAVA_INCLUDE_PATH2}" "-I${JAVA_AWT_INCLUDE_PATH}" 
            CACHE STRING "JDK compile includes") 
    endif()
    
    #
    # Find VTK
    #
    find_package(VTK 5.10 REQUIRED MODULE)
    if(VTK_FOUND)
        configure_file(${CMAKE_MODULE_PATH}/vtk_definitions.cmake.in ${CMAKE_BINARY_DIR}/vtk_definitions.cmake)
        include(${CMAKE_BINARY_DIR}/vtk_definitions.cmake)
    endif()   
    
    if(BUILD_BINDINGS)
         # Find Swig
        find_package(SWIG REQUIRED)
        if(SWIG_FOUND)
            include(${CMAKE_MODULE_PATH}/UseSWIG.cmake)
        endif()
        
        # Find C#
        find_package(CSharp)
        if(CSHARP_FOUND)
              include(${CMAKE_MODULE_PATH}/UseCSharp.cmake)
        endif()
            
        # Find Python  
        find_package(PythonLibs REQUIRED)
          
        # Find the JMF
        find_package(JMF REQUIRED)
            if(JMF_FOUND)
               configure_file(${CMAKE_MODULE_PATH}/jmf_definitions.cmake.in 
                   ${CMAKE_BINARY_DIR}/jmf_definitions.cmake)
               include(${CMAKE_BINARY_DIR}/jmf_definitions.cmake)
            endif()   
    endif()
endif()

