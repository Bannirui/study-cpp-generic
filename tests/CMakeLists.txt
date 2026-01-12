# 拷贝资源文件到构建目录和运行目录
add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/asset" "${CMAKE_CURRENT_BINARY_DIR}/asset"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/asset" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/asset"
        COMMENT "Copying assets to build and runtime directories"
)

# 构建时触发资源文件复制
add_executable(right_val_test right_val_test.cpp)
target_link_libraries(right_val_test PRIVATE ${PROJECT_NAME})
add_dependencies(right_val_test copy_assets)

add_executable(function_object_test function_object_test.cpp)
target_link_libraries(function_object_test PRIVATE ${PROJECT_NAME})
add_dependencies(function_object_test copy_assets)

add_executable(foreach_test foreach_test.cpp)
target_link_libraries(foreach_test PRIVATE ${PROJECT_NAME})
add_dependencies(foreach_test copy_assets)

add_executable(find_test find_test.cpp)
target_link_libraries(find_test PRIVATE ${PROJECT_NAME})
add_dependencies(find_test copy_assets)

add_executable(swap_test swap_test.cpp)
target_link_libraries(swap_test PRIVATE ${PROJECT_NAME})
add_dependencies(swap_test copy_assets)
