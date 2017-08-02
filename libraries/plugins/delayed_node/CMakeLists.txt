file(GLOB HEADERS "include/liteshares/delayed_node/*.hpp")

add_library( liteshares_delayed_node 
             delayed_node_plugin.cpp
           )

target_link_libraries( liteshares_delayed_node liteshares_chain liteshares_app )
target_include_directories( liteshares_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   liteshares_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
