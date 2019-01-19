macro(AddExternalFramework fwname appname libpath)
    find_library(FRAMEWORK_${fwname}
        NAMES ${fwname}
        PATHS ${libpath} 
        NO_DEFAULT_PATH)
    if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
        MESSAGE(ERROR ": Framework ${fwname} not found: ${FRAMEWORK_${fwname}}")
    else()
        TARGET_LINK_LIBRARIES(${appname} ${FRAMEWORK_${fwname}})
        MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
    endif()
endmacro(AddExternalFramework)

macro(AddSystemFramework fwname appname)
    find_library(FRAMEWORK_${fwname}
        NAMES ${fwname})
    if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
        MESSAGE(ERROR ": Framework ${fwname} not found: ${FRAMEWORK_${fwname}}")
    else()
        TARGET_LINK_LIBRARIES(${appname} ${FRAMEWORK_${fwname}})
        MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
    endif()
endmacro(AddSystemFramework)