file(GLOB HEADERS "include/liteshares/app/*.hpp")
file(GLOB EGENESIS_HEADERS "../egenesis/include/liteshares/app/*.hpp")

add_library( liteshares_app 
             api.cpp
             application.cpp
             database_api.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
             ${EGENESIS_HEADERS}
           )

# need to link liteshares_debug_witness because plugins aren't sufficiently isolated #246
target_link_libraries( liteshares_app liteshares_market_history liteshares_account_history liteshares_chain fc liteshares_db liteshares_net liteshares_utilities liteshares_debug_witness )
target_include_directories( liteshares_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            "${CMAKE_CURRENT_SOURCE_DIR}/../egenesis/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   liteshares_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/liteshares/app" )
