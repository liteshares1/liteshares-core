file(GLOB HEADERS "include/liteshares/account_history/*.hpp")

add_library( liteshares_account_history 
             account_history_plugin.cpp
           )

target_link_libraries( liteshares_account_history liteshares_chain liteshares_app )
target_include_directories( liteshares_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( account_history_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   liteshares_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/liteshares/account_history" )

