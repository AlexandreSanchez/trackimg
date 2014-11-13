set(filenames
        options.cpp
        trace.cpp
        trackimg.cpp
)

set(headers
        trackimg.h
        options.h
        trace.h
)

add_executable(trackimg ${filenames} ${headers})

target_link_libraries ( trackimg ${OpenCV_LIBS})
