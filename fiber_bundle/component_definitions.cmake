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
# This file contains declarations and functions unique to this component.
#

#
# Include functions and definitions common to all components.
# 
include(${CMAKE_MODULE_PATH}/component_functions.cmake)

#
# The current namespace
# The namespace should be ${COMPONENTS), but force it to remove all doubt.
#
set(NAME_SPACE fiber_bundle CACHE STRING "C++ namespace for this project" FORCE)

#
# Create the build/include folder
#
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include/${LPS_ID}/${NAME_SPACE})

#
# Define the clusters for this component.
#
set(clusters base_spaces dof_iterators dof_maps evaluators fiber_spaces general 
    id_spaces iterators matrices section_spaces examples template_instantiations)
    
#
# Initialize all variables for this component.
#
set_component_vars()

#
# Add the clusters to the project
#
add_clusters("${clusters}")

#
# Set the cumulative Java binding jar variable for this component.
#
set(${COMPONENT}_JAVA_BINDING_JARS ${SHEAF_JAVA_BINDING_JARS} 
    ${PROJECT_NAME}_java_binding.jar CACHE STRING 
    "Cumulative Java bindings jars for ${PROJECT_NAME}")

#------------------------------------------------------------------------------
# FUNCTION DEFINITION SECTION
#------------------------------------------------------------------------------

#
# Create the library targets for this component.
#
function(add_library_targets)

    if(WIN64INTEL OR WIN64MSVC)

        # Tell the linker where to look for this project's libraries.
        link_directories(${${COMPONENT}_OUTPUT_DIR})
        # Create the DLL.
        add_library(${${COMPONENT}_DYNAMIC_LIB} 
            SHARED ${${COMPONENT}_SRCS})
        add_dependencies(${${COMPONENT}_DYNAMIC_LIB} 
            ${SHEAF_IMPORT_LIB})

        target_link_libraries(${${COMPONENT}_DYNAMIC_LIB} 
            ${SHEAF_IMPORT_LIB})
        set_target_properties(${${COMPONENT}_DYNAMIC_LIB} 
            PROPERTIES FOLDER "Library Targets")
        # Override cmake's placing of "${${COMPONENT}_DYNAMIC_LIB}_EXPORTS 
        # into the preproc symbol table.
        set_target_properties(${${COMPONENT}_DYNAMIC_LIB} 
            PROPERTIES DEFINE_SYMBOL "SHEAF_DLL_EXPORTS")

    else() # Linux
    
        # Static library
        add_library(${${COMPONENT}_STATIC_LIB} 
            STATIC ${${COMPONENT}_SRCS})
        add_dependencies(${${COMPONENT}_STATIC_LIB} 
            ${SHEAF_STATIC_LIB})
        set_target_properties(${${COMPONENT}_STATIC_LIB} 
            PROPERTIES OUTPUT_NAME ${PROJECT_NAME} )

        # Shared library
        add_library(${${COMPONENT}_SHARED_LIB} 
            SHARED ${${COMPONENT}_SRCS})
        add_dependencies(${${COMPONENT}_SHARED_LIB} 
            ${SHEAF_SHARED_LIBS})
        set_target_properties(${${COMPONENT}_SHARED_LIB} 
            PROPERTIES OUTPUT_NAME ${PROJECT_NAME} LINKER_LANGUAGE CXX)
        
        # Override cmake's placing of "${COMPONENT_LIB}_EXPORTS into the preproc 
        # symbol table. CMake apparently detects the presence of cdecl_dllspec in 
        # the source and places -D<LIBRARY>_EXPORTS into the preproc symbol 
        # table no matter the platform.
        set_target_properties(${${COMPONENT}_SHARED_LIB} 
            PROPERTIES DEFINE_SYMBOL "")
 
        # Define the library version.
        set_target_properties(${${COMPONENT}_SHARED_LIB} 
            PROPERTIES VERSION ${LIB_VERSION}) 
    
        # Library alias definitions
        add_dependencies(${PROJECT_NAME}-shared-lib 
            ${${COMPONENT}_SHARED_LIBS})
        add_dependencies(${PROJECT_NAME}-static-lib 
            ${${COMPONENT}_STATIC_LIBS})
    
        target_link_libraries(${${COMPONENT}_SHARED_LIB} 
            ${SHEAF_SHARED_LIBS})
        target_link_libraries(${${COMPONENT}_STATIC_LIB} 
            ${SHEAF_STATIC_LIBS})

    endif()

endfunction(add_library_targets)

#
# Create the bindings targets for this component.
#
function(add_bindings_targets)

if(SWIG_FOUND AND BUILD_BINDINGS)  
        
    #
    # Java ###############################################
    #
    
    include_directories(${JAVA_INCLUDE_PATH} ${JAVA_INCLUDE_PATH2})
    include_directories(${SHEAF_JAVA_BINDING_SRC_DIR})
    include_directories(${SHEAF_COMMON_BINDING_SRC_DIR})
    include_directories(${${COMPONENT}_JAVA_BINDING_SRC_DIR})
    include_directories(${${COMPONENT}_COMMON_BINDING_SRC_DIR})        
       
    set_source_files_properties(
        ${${COMPONENT}_JAVA_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_JAVA_INTERFACE} 
        PROPERTIES CPLUSPLUS ON)
    
    # Add the java binding library target
    swig_add_module(${${COMPONENT}_JAVA_BINDING_LIB} java 
        ${${COMPONENT}_JAVA_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_JAVA_INTERFACE})
    
    if(WIN64INTEL OR WIN64MSVC)
        swig_link_libraries(${${COMPONENT}_JAVA_BINDING_LIB} 
            ${SHEAF_JAVA_BINDING_LIBS} ${${COMPONENT}_IMPORT_LIBS})
        set_target_properties(${${COMPONENT}_JAVA_BINDING_LIB} 
            PROPERTIES FOLDER "Binding Targets - Java")
    else()
        add_dependencies(${${COMPONENT}_JAVA_BINDING_LIB} 
            ${SHEAF_JAVA_BINDING_LIB} ${${COMPONENT}_SHARED_LIB})
        target_link_libraries(${${COMPONENT}_JAVA_BINDING_LIB} ${JDK_LIBS} 
            ${${COMPONENT}_SHARED_LIB})   
    endif()
    
    set_target_properties(${${COMPONENT}_JAVA_BINDING_LIB} 
        PROPERTIES LINKER_LANGUAGE CXX)
    # Define the library version.
    set_target_properties(${${COMPONENT}_JAVA_BINDING_LIB} 
        PROPERTIES VERSION ${LIB_VERSION})

    # Create the bindings jar file
    # Output path in windows differs slightly from Linux. Cmake wont allow a 
    # conditional inside add_custom_target, so we have to do it outside.
    if(WIN64INTEL OR WIN64MSVC)

        # Set the cumulative classpath variable for this component
        set(${COMPONENT}_CLASSPATH  ${SHEAF_CLASSPATH} 
            ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/${${COMPONENT}_JAVA_BINDING_JAR} 
            CACHE STRING "Cumulative classpath for ${PROJECT_NAME}" FORCE)

        add_custom_target(${PROJECT_NAME}_java_binding.jar ALL
               DEPENDS ${${COMPONENT}_JAVA_BINDING_LIB} ${SHEAF_JAVA_BINDING_JAR}
                set_target_properties(${PROJECT_NAME}_java_binding.jar 
                   PROPERTIES FOLDER "Component Binding Jars")
               COMMAND ${CMAKE_COMMAND} -E echo "Compiling Java files..."
               COMMAND ${Java_JAVAC_EXECUTABLE} -classpath ".;${SHEAF_CLASSPATH}" -d . *.java
               COMMAND ${CMAKE_COMMAND} -E echo "Creating jar file..."
               COMMAND ${Java_JAR_EXECUTABLE} cvf 
                   ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/${${COMPONENT}_JAVA_BINDING_JAR} 
                   ${LANG_BINDINGS_ROOT}/java/*.class
                   )
           
        # Java documentation
        if(DOC_TARGETS)
            add_custom_target(${PROJECT_NAME}-java-docs ALL
                    COMMAND ${Java_JAVADOC_EXECUTABLE} -windowtitle "${PROJECT_NAME} documentation" 
                    -classpath "${SHEAF_CLASSPATH}" 
                    -d  ${CMAKE_BINARY_DIR}/documentation/java/${PROJECT_NAME}  
                    *.java WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    DEPENDS ${${COMPONENT}_JAVA_BINDING_JAR}
                    )
          set_target_properties(${PROJECT_NAME}-java-docs 
              PROPERTIES FOLDER "Documentation Targets") 
          endif()                              
    else()
    
        set(${COMPONENT}_CLASSPATH ${SHEAF_CLASSPATH} 
            ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${${COMPONENT}_JAVA_BINDING_JAR} 
            CACHE STRING "Cumulative classpath for ${PROJECT_NAME}" FORCE)
        # The default list item separator in cmake is ";". If Linux, then exchange 
        # ";" for  the UNIX style ":" and store the result in parent_classpath.
        string(REGEX REPLACE ";" ":" parent_classpath "${SHEAF_CLASSPATH}")
        string(REGEX REPLACE ";" ":" this_classpath "${${COMPONENT}_CLASSPATH}")            
        add_custom_target(${PROJECT_NAME}_java_binding.jar ALL
            DEPENDS ${${COMPONENT}_JAVA_BINDING_LIB} ${SHEAF_JAVA_BINDING_JAR}
            COMMAND ${CMAKE_COMMAND} -E echo "Compiling Java files..."
            COMMAND ${Java_JAVAC_EXECUTABLE} -classpath "${parent_classpath}" -d . *.java
            COMMAND ${CMAKE_COMMAND} -E echo "Creating jar file..."
            COMMAND ${Java_JAR_EXECUTABLE} cvf 
                ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${${COMPONENT}_JAVA_BINDING_JAR} 
                ${JAVA_BINDINGS_ROOT}/*.class
         )
        # Java documentation
        if(DOC_TARGETS)
            add_custom_target(${PROJECT_NAME}-java-docs ALL
                    COMMAND ${Java_JAVADOC_EXECUTABLE} -windowtitle 
                    "${PROJECT_NAME} documentation" -classpath "${this_classpath}" 
                    -d  ${CMAKE_BINARY_DIR}/documentation/java/${PROJECT_NAME}  
                    *.java WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    DEPENDS ${${COMPONENT}_JAVA_BINDING_JAR}
                             )
        endif()
    endif()
          
    set_target_properties(${PROJECT_NAME}_java_binding.jar 
        PROPERTIES FOLDER "Library Jars") 
    mark_as_advanced(FORCE ${COMPONENT}_CLASSPATH) 

    #
    # CSharp #############################################
    #
    
    set(CMAKE_SWIG_FLAGS -c++ -w842 -namespace fiber_bundle)
    
    include_directories(${SHEAF_CSHARP_BINDING_SRC_DIR})
       
    # Add the csharp binding library target
    set_source_files_properties(
        ${${COMPONENT}_CSHARP_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_CSHARP_INTERFACE} 
        PROPERTIES CPLUSPLUS ON)
    swig_add_module(${${COMPONENT}_CSHARP_BINDING_LIB} csharp 
        ${${COMPONENT}_CSHARP_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_CSHARP_INTERFACE})
    if(WIN64INTEL OR WIN64MSVC)
        swig_link_libraries(${${COMPONENT}_CSHARP_BINDING_LIB} 
            ${SHEAF_CSHARP_BINDING_LIB} ${${COMPONENT}_IMPORT_LIB} ${CSHARP_LIBRARY})
        set_target_properties(${${COMPONENT}_CSHARP_BINDING_LIB} 
            PROPERTIES FOLDER "Binding Targets - CSharp")
    else()
        add_dependencies(${${COMPONENT}_CSHARP_BINDING_LIB} 
            ${SHEAF_CSHARP_BINDING_LIB} ${${COMPONENT}_SHARED_LIB})
        target_link_libraries(${${COMPONENT}_CSHARP_BINDING_LIB} 
            ${SHEAF_CSHARP_BINDING_LIB} ${${COMPONENT}_SHARED_LIB})
    endif()    
        set_target_properties(${${COMPONENT}_CSHARP_BINDING_LIB} 
            PROPERTIES LINKER_LANGUAGE CXX)

    # Define the library version.
    set_target_properties(${${COMPONENT}_CSHARP_BINDING_LIB} 
        PROPERTIES VERSION ${LIB_VERSION})
    
    # Create the csharp assembly
    if(WIN64INTEL OR WIN64MSVC)
        add_custom_target(${${COMPONENT}_CSHARP_BINDING_ASSY} ALL
            COMMAND ${CMAKE_COMMAND} -E echo ""
            COMMAND ${CMAKE_COMMAND} -E echo "Creating Csharp Binding for ${PROJECT_NAME} ..."
            COMMAND ${CMAKE_COMMAND} -E echo ""                 
            COMMAND ${CSHARP_COMPILER} /nologo /noconfig /warn:1 
            /errorreport:prompt /target:library 
            /out:${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/${${COMPONENT}_CSHARP_BINDING_ASSY} 
            ${CMAKE_CURRENT_BINARY_DIR}/*.cs
            )
    else()
        add_custom_target(${${COMPONENT}_CSHARP_BINDING_ASSY} ALL
                    COMMAND ${CSHARP_COMPILER} -target:library 
                    -nowarn:0114,0108 
                    -out:${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${${COMPONENT}_CSHARP_BINDING_ASSY} 
                    ${CMAKE_CURRENT_BINARY_DIR}/*.cs
        )
    endif()

    add_dependencies(${${COMPONENT}_CSHARP_BINDING_ASSY} 
        ${${COMPONENT}_CSHARP_BINDING_LIB})        
    set_target_properties(${${COMPONENT}_CSHARP_BINDING_ASSY} 
        PROPERTIES FOLDER "CSharp Assembly Targets")
             
    #
    # Python ############################################# 
    #
    
    set(CMAKE_SWIG_FLAGS -c++ )
    include_directories(${PYTHON_INCLUDE_PATH})
    
    include_directories(${SHEAF_PYTHON_BINDING_SRC_DIR})
           
    set_source_files_properties(${${COMPONENT}_PYTHON_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_PYTHON_INTERFACE} 
        PROPERTIES CPLUSPLUS ON)
    swig_add_module(${${COMPONENT}_PYTHON_BINDING_LIB} python 
        ${${COMPONENT}_PYTHON_BINDING_SRC_DIR}/${${COMPONENT}_SWIG_PYTHON_INTERFACE})
    
    if(WIN64INTEL OR WIN64MSVC)
        add_dependencies(${${COMPONENT}_PYTHON_BINDING_LIB} 
            ${SHEAF_PYTHON_BINDING_LIBS} 
            ${${COMPONENT}_IMPORT_LIBS})
        swig_link_libraries(${${COMPONENT}_PYTHON_BINDING_LIB} 
            ${SHEAF_PYTHON_BINDING_LIBS} ${${COMPONENT}_IMPORT_LIB} 
            ${PYTHON_LIBRARY} )
        set_target_properties(${${COMPONENT}_PYTHON_BINDING_LIB} 
            PROPERTIES FOLDER "Binding Targets - Python")
    else()
        add_dependencies(${${COMPONENT}_PYTHON_BINDING_LIB} 
            ${SHEAF_PYTHON_BINDING_LIBS} 
            ${${COMPONENT}_SHARED_LIBS})
        swig_link_libraries(${${COMPONENT}_PYTHON_BINDING_LIB} 
            ${SHEAF_PYTHON_BINDING_LIBS} 
            ${${COMPONENT}_SHARED_LIBS})
    endif()
    
    set_target_properties(${${COMPONENT}_PYTHON_BINDING_LIB} 
        PROPERTIES LINKER_LANGUAGE CXX)

    # Define the library version.
    set_target_properties(${${COMPONENT}_PYTHON_BINDING_LIB} 
        PROPERTIES VERSION ${LIB_VERSION})  

    # Guard these until we can get the VS solution explorer aesthetic issues sorted
    if(LINUX64GNU OR LINUX64INTEL) 
        add_dependencies(${PROJECT_NAME}-java-binding ${PROJECT_NAME}_java_binding.jar)    
        add_dependencies(${PROJECT_NAME}-python-binding ${${COMPONENT}_PYTHON_BINDING_LIB})
        add_dependencies(${PROJECT_NAME}-csharp-binding ${${COMPONENT}_CSHARP_BINDING_LIB})
    endif()

    # Bindings target aliases already declared at system level. 
    # Add dependencies here.
   add_dependencies(${PROJECT_NAME}-bindings 
       ${PROJECT_NAME}_java_binding.jar ${${COMPONENT}_PYTHON_BINDING_LIB} 
       ${${COMPONENT}_CSHARP_BINDING_LIB})
endif()

endfunction(add_bindings_targets)

# 
# Set the commands for the install target
#
function(add_install_target)

    if(LINUX64INTEL OR LINUX64GNU)
        install(TARGETS ${${COMPONENT}_SHARED_LIB} EXPORT 
            ${${COMPONENT}_SHARED_LIB} LIBRARY DESTINATION 
            ${CMAKE_BUILD_TYPE}/lib)
        install(TARGETS ${${COMPONENT}_STATIC_LIB} ARCHIVE 
            DESTINATION ${CMAKE_BUILD_TYPE}/lib)

        if(SWIG_FOUND AND BUILD_BINDINGS)
            install(TARGETS ${${COMPONENT}_JAVA_BINDING_LIB} LIBRARY 
                DESTINATION ${CMAKE_BUILD_TYPE}/lib)
            install(FILES ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${${COMPONENT}_JAVA_BINDING_JAR} 
                DESTINATION ${CMAKE_BUILD_TYPE}/lib)  
            # Only install python binding if the component has a target for it.
            if(TARGET ${${COMPONENT}_PYTHON_BINDING_LIB})
                install(TARGETS ${${COMPONENT}_PYTHON_BINDING_LIB} LIBRARY 
                    DESTINATION ${CMAKE_BUILD_TYPE}/lib)
            endif()
            install(TARGETS ${${COMPONENT}_CSHARP_BINDING_LIB} LIBRARY 
                DESTINATION ${CMAKE_BUILD_TYPE}/lib)
            install(
                FILES ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_CSHARP_BINDING_ASSY} 
                DESTINATION ${CMAKE_BUILD_TYPE}/lib)             
        endif()
        
    elseif(WIN64INTEL OR WIN64MSVC)

        # The BUILD_TYPE variable will be set while CMake is processing the install files. It is not set at configure time
        # for this project. We pass it literally here.
 #       install(TARGETS ${${COMPONENT}_IMPORT_LIB} EXPORT 
#            ${${COMPONENT}_IMPORT_LIB} ARCHIVE DESTINATION lib/\${BUILD_TYPE} INCLUDES DESTINATION include/ComLimitPoint/SheafSystem)
#        install(EXPORT ${${COMPONENT}_IMPORT_LIB} DESTINATION lib)
                      
#        install(TARGETS ${${COMPONENT}_DYNAMIC_LIB} RUNTIME 
#            DESTINATION bin/\${BUILD_TYPE}  INCLUDES DESTINATION include/ComLimitPoint/SheafSystem)
#        install(EXPORT ${${COMPONENT}_IMPORT_LIB} DESTINATION bin) 
         install(TARGETS  ${PROJECT_NAME} EXPORT SheafSystem 
                ARCHIVE DESTINATION lib/\${BUILD_TYPE} 
                RUNTIME DESTINATION bin/\${BUILD_TYPE} 
                INCLUDES DESTINATION include/ComLimitPoint/SheafSystem)
         install(EXPORT SheafSystem DESTINATION bin) 
         install(EXPORT SheafSystem DESTINATION lib)
                
#        install(FILES 
#            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_DYNAMIC_LIB}_d.pdb 
#            DESTINATION bin/\${BUILD_TYPE} OPTIONAL)
#        install(FILES 
#            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_DYNAMIC_LIB}.pdb 
#            DESTINATION bin/\${BUILD_TYPE} OPTIONAL)
                            
#        if(SWIG_FOUND AND BUILD_BINDINGS)
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_JAVA_BINDING_LIB}_d.pdb 
#                DESTINATION bin/\${BUILD_TYPE} OPTIONAL)                
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_CSHARP_BINDING_LIB}_d.pdb 
#                DESTINATION bin/\${BUILD_TYPE} OPTIONAL) 
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_JAVA_BINDING_LIB}.pdb 
#                DESTINATION bin/\${BUILD_TYPE} OPTIONAL)                
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_CSHARP_BINDING_LIB}.pdb 
#                DESTINATION bin/\${BUILD_TYPE} OPTIONAL) 
#            install(FILES 
#                ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_JAVA_BINDING_JAR} 
#                DESTINATION lib/\${BUILD_TYPE})  
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_PYTHON_BINDING_LIB}_d.pdb 
 #               DESTINATION bin/\${BUILD_TYPE} OPTIONAL) 
#            install(FILES 
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_PYTHON_BINDING_LIB}.pdb 
#                DESTINATION bin/\${BUILD_TYPE} OPTIONAL) 
#            install(FILES
#                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/\${BUILD_TYPE}/${${COMPONENT}_CSHARP_BINDING_ASSY} 
#                DESTINATION bin/\${BUILD_TYPE})              
#        endif()
    endif()

    install(FILES ${${COMPONENT}_INCS} DESTINATION include) 
                         
endfunction(add_install_target)

