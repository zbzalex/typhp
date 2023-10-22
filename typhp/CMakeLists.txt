cmake_minimum_required(VERSION 3.10)

project(typhp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
	-Wall
	-Wextra
	-Wpedantic
)

add_compile_definitions(
	TYPHP_DEBUG=1
)

add_executable(typhp
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Lexer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ASTNode.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Comment.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PhpStartTag.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PhpCloseTag.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IncludeStmt.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IncludeOnceStmt.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Literal.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Num.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HtmlText.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BinOp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ConstAccess.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/VarAccess.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/VarDecl.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FunctionCall.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FunctionDecl.cpp
)
