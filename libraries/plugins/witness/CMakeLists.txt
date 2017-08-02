file(GLOB HEADERS "include/liteshares/witness/*.hpp")

add_library( liteshares_witness 
             witness.cpp
           )

target_link_libraries( liteshares_witness liteshares_chain liteshares_app )
target_include_directories( liteshares_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   liteshares_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
