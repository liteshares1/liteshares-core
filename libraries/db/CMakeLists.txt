file(GLOB HEADERS "include/liteshares/db/*.hpp")
add_library( liteshares_db undo_database.cpp index.cpp object_database.cpp ${HEADERS} )
target_link_libraries( liteshares_db fc )
target_include_directories( liteshares_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   liteshares_db

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/liteshares/db" )
