include_guard()

# used to share compiler flags & definition.
add_library(ezcc_global INTERFACE)

target_compile_definitions(ezcc_global INTERFACE "EZCC")
