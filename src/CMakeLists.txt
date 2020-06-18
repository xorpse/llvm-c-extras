include_directories(${CMAKE_SOURCE_DIR}/include)

set(LLVM_C_EXTRAS_SOURCE_FILES
  llvm-core-extras.cc
  )

add_library(llvm-c-extras
  ${LLVM_C_EXTRAS_SOURCE_FILES}
  )

target_include_directories(llvm-c-extras
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

target_link_libraries(llvm-c-extras
  ${LLVM_LIBRARIES}
  )

include(GNUInstallDirs)

install(TARGETS llvm-c-extras
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
