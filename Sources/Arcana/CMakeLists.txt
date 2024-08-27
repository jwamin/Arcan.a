CHECK_SYMBOL_EXISTS(arc4random_uniform stdlib.h HAS_ARC4RANDOM)

message("Arcana build cmake - hasarc4random:${HAS_ARC4RANDOM}")

add_library(arcan arcana.c arcana.h arcana-types.h)
if(${HAS_ARC4RANDOM})
add_compile_definitions(arcan PUBLIC _HAS_ARC4RANDOM)
else()
	target_link_libraries(arcan bsd)
endif()
