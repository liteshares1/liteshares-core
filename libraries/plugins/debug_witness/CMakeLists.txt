file(GLOB HEADERS "include/liteshares/debug_witness/*.hpp")

add_library( liteshares_debug_witness
             debug_api.cpp
             debug_witness.cpp
           )

target_link_libraries( liteshares_debug_witness liteshares_chain liteshares_app )
target_include_directories( liteshares_debug_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   liteshares_debug_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
