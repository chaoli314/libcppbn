project(bn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(HEADER_FILES

        Node.h
        BayesianNetwork.h

        BasicClass.h
        typedefs.h

        ADTree.h
        contingency_table.h

        var.h
        sorted_set.h

        Factor.h
        HuginFormatFile.h
        varset.h)

set(SOURCE_FILES
        BasicClass.cpp
        )

add_library(bn STATIC ${SOURCE_FILES} ${HEADER_FILES})
