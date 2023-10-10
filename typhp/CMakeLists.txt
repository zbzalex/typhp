cmake_minimum_required(VERSION 3.10)

project(typhp)

add_executable(typhp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/Lexer.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/ASTNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ASTFunction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ASTClass.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ASTArg.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Generator.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/Analyzer.cpp
)
