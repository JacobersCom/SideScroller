add_library(project
	includes/WindowManager.h
	includes/WindowManager.cpp
	includes/main.cpp
	includes/Defines.h
)

target_link_directories(project
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_link_libraries(project
	PUBLIC
	SDL3::SDL3
)
